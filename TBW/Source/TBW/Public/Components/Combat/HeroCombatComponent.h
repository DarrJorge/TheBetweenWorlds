// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/CombatComponentBase.h"
#include "HeroCombatComponent.generated.h"


class ATBWHeroWeapon;

UCLASS()
class TBW_API UHeroCombatComponent : public UCombatComponentBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="TBW|Combat")
	ATBWHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag WeaponTag) const;
	
};
