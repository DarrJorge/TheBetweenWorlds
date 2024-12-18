// DarrJorge All Rights Reserved.


#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "TBWGameplayTags.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"
#include "Utils/TBW_Debug.h"

void UTBWAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InputTag)
{
	for (const auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;
		const bool bToggleAbility = InputTag.MatchesTag(TBWGameplayTags::InputTag_Toggleable) && AbilitySpec.IsActive();

		if (bToggleAbility)
		{
			CancelAbilityHandle(AbilitySpec.Handle);
		}
		else
		{
			TryActivateAbility(AbilitySpec.Handle);
		}
	}
}

void UTBWAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid() || !InputTag.MatchesTag(TBWGameplayTags::InputTag_KeyMustBeHeld))
	{
		return;
	}

	for (const auto& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag) && AbilitySpec.IsActive())
		{
			CancelAbilityHandle(AbilitySpec.Handle);
		}
	}
}

void UTBWAbilitySystemComponent::GrantCharacterWeaponAbilities(const TArray<FHeroAbilitySet>& DefaultWeaponAbilities,
	int32 InLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if (DefaultWeaponAbilities.IsEmpty()) return;

	for (const auto& AbilitySet : DefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = InLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UTBWAbilitySystemComponent::RemoveGrantedCharacterWeaponAbilities(TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles)
{
	if (InGrantedAbilitySpecHandles.IsEmpty()) return;
	for (const auto& SpecHandle : InGrantedAbilitySpecHandles)
	{
		if (!SpecHandle.IsValid()) continue;
		ClearAbility(SpecHandle);
	}
	InGrantedAbilitySpecHandles.Empty();
}

bool UTBWAbilitySystemComponent::TryActivateAbilityByTag(const FGameplayTag& InAbilityTag)
{
	if (!InAbilityTag.IsValid()) return false;

	TArray<FGameplayAbilitySpec*> FoundAbilitySpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(InAbilityTag.GetSingleTagContainer(), FoundAbilitySpecs);
	if (FoundAbilitySpecs.IsEmpty()) return false;

	const auto RandomIndex = FMath::RandRange(0, FoundAbilitySpecs.Num() - 1);
	const auto* AbilitySpec = FoundAbilitySpecs[RandomIndex];
	if (!AbilitySpec || AbilitySpec->IsActive()) return false;

	return TryActivateAbility(AbilitySpec->Handle);
}
