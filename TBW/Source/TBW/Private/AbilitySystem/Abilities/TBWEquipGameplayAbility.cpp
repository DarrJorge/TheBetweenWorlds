// DarrJorge All Rights Reserved.


#include "AbilitySystem/Abilities/TBWEquipGameplayAbility.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/TBWHeroWeapon.h"
#include "Controllers/TBWPlayerController.h"
#include "Animations/Hero/TBWHeroLinkedAnimLayer.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"

void UTBWEquipGameplayAbility::HandleEquipWeapon(const FGameplayTag& WeaponTag)
{
	const auto* Weapon = GetHeroCombatComponentFromActorInfo()->GetHeroCarriedWeaponByTag(WeaponTag);
	check(Weapon);
	check(Weapon->WeaponData.WeaponAnimLayer);
	check(Weapon->WeaponData.WeaponMappingContext);

	// override character locomotion animations by weapon
	GetOwningComponentFromActorInfo()->LinkAnimClassLayers(Weapon->WeaponData.WeaponAnimLayer);

	// override input context for weapon
	if (const auto* PlayerController = GetHeroControllerFromActorInfo())
	{
		if (auto* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			InputSystem->AddMappingContext(Weapon->WeaponData.WeaponMappingContext, 1);
		}
	}

	// add new abilities to character by weapon
	if (auto* TbwASC = Cast<UTBWAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo()))
	{
		TbwASC->GrantCharacterWeaponAbilities(Weapon->WeaponData.DefaultWeaponAbilities, GetAbilityLevel(), GrantedAbilitySpecHandles);
	}

	GetCombatComponentBaseFromActorInfo()->CurrentEquippedWeaponTag = WeaponTag;
}

void UTBWEquipGameplayAbility::HandleUnequipWeapon(const FGameplayTag& WeaponTag)
{
	const auto* Weapon = GetHeroCombatComponentFromActorInfo()->GetHeroCarriedWeaponByTag(WeaponTag);
	check(Weapon);
	check(Weapon->WeaponData.WeaponAnimLayer);
	check(Weapon->WeaponData.WeaponMappingContext);

	// return to unarmed character locomotion animations
	GetOwningComponentFromActorInfo()->UnlinkAnimClassLayers(Weapon->WeaponData.WeaponAnimLayer);

	// cleared weapon input context
	if (const auto* PlayerController = GetHeroControllerFromActorInfo())
	{
		if (auto* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			InputSystem->RemoveMappingContext(Weapon->WeaponData.WeaponMappingContext);
		}
	}

	// remove weapon abilities from character
	if (auto* TbwASC = Cast<UTBWAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo()))
	{
		TbwASC->RemoveGrantedCharacterWeaponAbilities(GrantedAbilitySpecHandles);
	}

	GetCombatComponentBaseFromActorInfo()->CurrentEquippedWeaponTag = FGameplayTag();
}
