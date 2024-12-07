// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "TBW_InventorySlotWidget.generated.h"

class UDataAsset_ItemInfo;
struct FItemData;
class UTextBlock;
class UProgressBar;
class UBorder;

UCLASS()
class TBW_API UTBW_InventorySlotWidget : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> AmmoText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> DamageText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> QuantityText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> WeightText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UProgressBar> ItemHP;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UBorder> ItemIcon;

	UPROPERTY(BlueprintReadWrite)
	bool bSlotFilled{false};

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UDataAsset_ItemInfo> ItemAsset;

	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable)
	void UpdateData(const FItemData& InData);

private:

	void SetQuantityText(int32 InQuantity) const;
	void SetWeightText(float InWeightUnitItem, int32 InQuantity) const;
	void SetDamageText(int32 InDamage) const ;
	void SetAmmoText(bool UseAmmo, int32 InCurrentAmmo, int32 InMaxAmmo) const;
	void SetSlotIcon(UTexture2D* InIconTexture) const;
	void SetItemHPBar(int32 InCurrentHP, int32 InMaxHP) const;
	void ClearData();
};
