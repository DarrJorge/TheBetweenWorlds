// DarrJorge All Rights Reserved.


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/TBWHeroWeapon.h"

ATBWHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag WeaponTag) const
{
	return Cast<ATBWHeroWeapon>(GetCarriedWeaponByTag(WeaponTag));
}
