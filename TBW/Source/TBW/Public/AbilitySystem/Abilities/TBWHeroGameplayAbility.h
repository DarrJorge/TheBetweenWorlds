// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"
#include "TBWHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class ATBWPlayerController;
class ATBWHeroCharacter;


UCLASS()
class TBW_API UTBWHeroGameplayAbility : public UTBWGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="TBW|Ability")
	ATBWHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="TBW|Ability")
	ATBWPlayerController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category="TBW|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ATBWHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<ATBWPlayerController> CachedHeroController;
	
};
