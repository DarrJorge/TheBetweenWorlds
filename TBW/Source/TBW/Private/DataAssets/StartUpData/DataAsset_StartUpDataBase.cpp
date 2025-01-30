// DarrJorge All Rights Reserved.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"

void UDataAsset_StartUpDataBase::InitStartupAbilities(UTBWAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	if (!InASC) return;
	
	InASC->GrantGameplayEffects(StartUpGameplayEffects, ApplyLevel);
	InASC->GrantAbilities(ActivateOnGivenAbilities, ApplyLevel);
	InASC->GrantAbilities(ReactiveAbilities, ApplyLevel);
}
