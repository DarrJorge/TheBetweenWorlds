// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Types/TBW_Enums.h"
#include "DataAsset_ItemInfo.generated.h"

class ATBW_ItemBase;

UCLASS(Blueprintable)
class TBW_API UDataAsset_ItemInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	TObjectPtr<UTexture2D> ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	FText ItemDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 ItemDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	EItemRarity ItemRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	bool bStackable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 StackSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	EItemType ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	TSoftClassPtr<ATBW_ItemBase> ItemClassRef;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	EArmorType ArmorType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	bool bUseAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 ItemCurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 MaxCurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemInfo")
	float ItemWeight;
};
