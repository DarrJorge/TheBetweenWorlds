// DarrJorge All Rights Reserved.

#pragma once

#include "GameplayTagContainer.h"
#include "Abilities/GameplayAbility.h"
#include "TBW_StructTypes.generated.h"

class UTBWGameplayAbility;
class UTBWHeroLinkedAnimLayer;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UTBWGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UTBWHeroLinkedAnimLayer> WeaponAnimLayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputTag"))
	TArray<FHeroAbilitySet> DefaultWeaponAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FScalableFloat WeaponBaseDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> WeaponIconTexture;
};

class UDataAsset_ItemInfo;

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 ItemID{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 ItemQuantity{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<UDataAsset_ItemInfo> ItemAsset;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 CurrentHP{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 MaxHP{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 CurrentAmmo{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 MaxAmmo{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 StackSize{0};

};
