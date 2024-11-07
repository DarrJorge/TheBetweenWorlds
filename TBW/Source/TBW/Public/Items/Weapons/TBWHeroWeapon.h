// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/TBWWeaponBase.h"
#include "Types/TBW_StructTypes.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"
#include "TBWHeroWeapon.generated.h"


UCLASS()
class TBW_API ATBWHeroWeapon : public ATBWWeaponBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TBW|WeaponData")
	FWeaponData WeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintCallable)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
	
};
