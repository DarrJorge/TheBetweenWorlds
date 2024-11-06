// DarrJorge All Rights Reserved.

#include "Types/TBW_StructTypes.h"
#include "AbilitySystem/Abilities/TBWGameplayAbility.h"


bool FHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
