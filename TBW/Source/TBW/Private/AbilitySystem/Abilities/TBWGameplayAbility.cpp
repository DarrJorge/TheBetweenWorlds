// DarrJorge All Rights Reserved.


#include "AbilitySystem/Abilities/TBWGameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "Components/Combat/CombatComponentBase.h"

void UTBWGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == ETBWAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UTBWGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == ETBWAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UCombatComponentBase* UTBWGameplayAbility::GetCombatComponentBaseFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UCombatComponentBase>();
}

UTBWAbilitySystemComponent* UTBWGameplayAbility::GetTBWAbilitySystemComponentFromActorInfo() const
{
	return Cast<UTBWAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
