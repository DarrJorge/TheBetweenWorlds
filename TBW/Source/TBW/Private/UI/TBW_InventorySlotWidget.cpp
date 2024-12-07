// DarrJorge All Rights Reserved.


#include "UI/TBW_InventorySlotWidget.h"

#include "Components/Border.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Engine/AssetManager.h"
#include "Types/TBW_StructTypes.h"
#include "DataAssets/Inventory/DataAsset_ItemInfo.h"

void UTBW_InventorySlotWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UTBW_InventorySlotWidget::UpdateData(const FItemData& InData)
{
	bSlotFilled = true;

	if (InData.ItemID == 0)
	{
		ClearData();
		return;
	}

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		InData.ItemAsset.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this, InData]()
			{
				if (UDataAsset_ItemInfo* LoadedAsset = InData.ItemAsset.Get())
				{
					ItemAsset = LoadedAsset;
					
					SetWeightText(LoadedAsset->ItemWeight, InData.ItemQuantity);
					SetSlotIcon(LoadedAsset->ItemIcon);

					switch (LoadedAsset->ItemType)
					{
						case EItemType::Resource:
						case EItemType::Buildable:
							SetQuantityText(InData.ItemQuantity);
							break;

						case EItemType::Equippable:
							SetDamageText(LoadedAsset->ItemDamage);
							SetItemHPBar(InData.CurrentHP, InData.MaxHP);
							SetAmmoText(LoadedAsset->bUseAmmo, InData.CurrentAmmo, InData.MaxAmmo);
							break;

						case EItemType::Consumable:
							SetQuantityText(InData.ItemQuantity);
							SetItemHPBar(InData.CurrentHP, InData.MaxHP);
							DamageText->SetVisibility(ESlateVisibility::Hidden);
							break;

						case EItemType::Armor:
							AmmoText->SetVisibility(ESlateVisibility::Hidden);
							SetItemHPBar(InData.CurrentHP, InData.MaxHP);
							SetDamageText(LoadedAsset->ItemDamage);
							break;
					}
				}
			}));
	
}

void UTBW_InventorySlotWidget::SetQuantityText(int32 InQuantity) const
{
	QuantityText->SetText(FText::FromString(FString::Printf(TEXT("x%d"), InQuantity)));
	QuantityText->SetVisibility(ESlateVisibility::Visible);
	DamageText->SetVisibility(ESlateVisibility::Hidden);
	AmmoText->SetVisibility(ESlateVisibility::Hidden);
	ItemHP->SetVisibility(ESlateVisibility::Hidden);
}

void UTBW_InventorySlotWidget::SetWeightText(float InWeightUnitItem, int32 InQuantity) const
{
	WeightText->SetText(FText::FromString(FString::Printf(TEXT("%f"), InWeightUnitItem*InQuantity)));
	WeightText->SetVisibility(ESlateVisibility::Visible);
}

void UTBW_InventorySlotWidget::SetDamageText(int32 InDamage) const
{
	DamageText->SetText(FText::FromString(FString::Printf(TEXT("DMG%d"), InDamage)));
	DamageText->SetVisibility(ESlateVisibility::Visible);
}

void UTBW_InventorySlotWidget::SetAmmoText(bool UseAmmo, int32 InCurrentAmmo, int32 InMaxAmmo) const
{
	if (!UseAmmo)
	{
		AmmoText->SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	AmmoText->SetVisibility(ESlateVisibility::Visible);
	AmmoText->SetText(FText::FromString(FString::Printf(TEXT("%d/%d"), InCurrentAmmo, InMaxAmmo)));
}

void UTBW_InventorySlotWidget::SetSlotIcon(UTexture2D* InIconTexture) const
{
	if (!InIconTexture) return;
	ItemIcon->SetBrushFromTexture(InIconTexture);
	ItemIcon->SetVisibility(ESlateVisibility::Visible);
}

void UTBW_InventorySlotWidget::SetItemHPBar(int32 InCurrentHP, int32 InMaxHP) const
{
	check(InMaxHP);
	ItemHP->SetPercent(InCurrentHP / InMaxHP);
	ItemHP->SetVisibility(ESlateVisibility::Visible);
}

void UTBW_InventorySlotWidget::ClearData()
{
	bSlotFilled = false;
	ItemHP->SetVisibility(ESlateVisibility::Hidden);
	ItemIcon->SetVisibility(ESlateVisibility::Hidden);
	AmmoText->SetVisibility(ESlateVisibility::Hidden);
	DamageText->SetVisibility(ESlateVisibility::Hidden);
	WeightText->SetVisibility(ESlateVisibility::Hidden);
	QuantityText->SetVisibility(ESlateVisibility::Hidden);
}
