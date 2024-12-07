// DarrJorge All Rights Reserved.


#include "Items/Weapons/TBWHeroWeapon.h"

void ATBWHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle>& ATBWHeroWeapon::GetGrantedAbilitySpecHandles()
{
	return GrantedAbilitySpecHandles;
}
