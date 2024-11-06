// DarrJorge All Rights Reserved.

#pragma once

#include "NativeGameplayTags.h"

namespace TBWGameplayTags
{
	/** Input Tags **/
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipWeapon);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipWeapon);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Jump);

	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_KeyMustBeHeld);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_KeyMustBeHeld_Block);

	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Toggleable);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Toggleable_TargetLock);

	/** Items Tags **/
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Item_Weapon_StaffBase);

	/** Player Tags **/
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_EquipWeapon);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Jump);
	
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Staff);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Staff);
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Jump);
	
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Melee_Unarmed);
	
	TBW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_Falling);
}
