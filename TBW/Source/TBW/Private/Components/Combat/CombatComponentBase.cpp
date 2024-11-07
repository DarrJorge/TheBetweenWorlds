// DarrJorge All Rights Reserved.


#include "Components/Combat/CombatComponentBase.h"
#include "Items/Weapons/TBWWeaponBase.h"


void UCombatComponentBase::RegisterWeapon(FGameplayTag InWeaponTag, ATBWWeaponBase* InWeapon, bool bRegisterAsEquippedWeapon)
{
	checkf(!CarriedWeaponMap.Contains(InWeaponTag), TEXT("A named %s has already been added as carried weapon"), *InWeaponTag.ToString());
	check(InWeapon);

	CarriedWeaponMap.Emplace(InWeaponTag, InWeapon);

	//InWeapon->OnWeaponHitTarget.BindUObject(this, &UCombatComponentBase::OnHitTargetActor);
	//InWeapon->OnWeaponPulledFromTarget.BindUObject(this, &UCombatComponentBase::OnWeaponPulledFromTargetActor);
	
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTag;
	}
}

ATBWWeaponBase* UCombatComponentBase::GetCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	if (CarriedWeaponMap.Contains(InWeaponTag))
	{
		if (auto* const* FoundWeapon = CarriedWeaponMap.Find(InWeaponTag))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

ATBWWeaponBase* UCombatComponentBase::GetCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid()) return nullptr;
	return GetCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UCombatComponentBase::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
}

float UCombatComponentBase::GetCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return 0.f;
}

void UCombatComponentBase::OnHitTargetActor(AActor* HitActor)
{
	// implementation in derived classes
}

void UCombatComponentBase::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	// implementation in derived classes
}
