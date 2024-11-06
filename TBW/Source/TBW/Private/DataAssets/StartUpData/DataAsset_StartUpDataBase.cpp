// DarrJorge All Rights Reserved.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameplayEffect.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UTBWAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	GrantAbilities(ActivateOnGivenAbilities, InASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, ApplyLevel);

	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			const auto* GameplayEffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASC->ApplyGameplayEffectToSelf(GameplayEffectCDO, ApplyLevel, InASC->MakeEffectContext());
		}
	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UTBWGameplayAbility>>& InAbilitiesToGive,
	UTBWAbilitySystemComponent* InASC, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const TSubclassOf<UTBWGameplayAbility>& Ability : InAbilitiesToGive)
	{
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASC->GiveAbility(AbilitySpec);
	}
}
