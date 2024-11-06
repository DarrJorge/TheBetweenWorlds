// DarrJorge All Rights Reserved.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"


void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UTBWAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASC, ApplyLevel);

	for (const auto& AbilitySet : HeroAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASC->GiveAbility(AbilitySpec);
	}
}
