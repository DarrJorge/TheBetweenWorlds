// DarrJorge All Rights Reserved.


#include "AbilitySystem/Abilities/TBWHeroGameplayAbility.h"
#include "Characters/TBWHeroCharacter.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "Controllers/TBWPlayerController.h"

ATBWHeroCharacter* UTBWHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedHeroCharacter.IsValid())
	{
		CachedHeroCharacter = Cast<ATBWHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

ATBWPlayerController* UTBWHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedHeroController.IsValid())
	{
		CachedHeroController = Cast<ATBWPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedHeroController.IsValid() ? CachedHeroController.Get() : nullptr;
}

UHeroCombatComponent* UTBWHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	check(GetHeroCharacterFromActorInfo());
	return Cast<UHeroCombatComponent>(GetHeroCharacterFromActorInfo()->GetPawnCombatComponent());
}