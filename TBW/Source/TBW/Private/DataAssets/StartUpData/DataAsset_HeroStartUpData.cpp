// DarrJorge All Rights Reserved.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"

void UDataAsset_HeroStartUpData::InitStartupAbilities(UTBWAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	Super::InitStartupAbilities(InASC, ApplyLevel);

	if (!InASC) return;

	for (const auto& AbilitySet : HeroAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;
		InASC->GrantAbilityWithTag(AbilitySet.AbilityToGrant, AbilitySet.InputTag, ApplyLevel);
	}
}
