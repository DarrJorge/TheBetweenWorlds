// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TBWHeroGameplayAbility.h"
#include "TBWEquipGameplayAbility.generated.h"


UCLASS()
class TBW_API UTBWEquipGameplayAbility : public UTBWHeroGameplayAbility
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable)
	void HandleEquipWeapon(const FGameplayTag& WeaponTag);

	UFUNCTION(BlueprintCallable)
	void HandleUnequipWeapon(const FGameplayTag& WeaponTag);
	
};
