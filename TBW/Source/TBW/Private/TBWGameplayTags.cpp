#include "TBWGameplayTags.h"


namespace TBWGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip_Weapon, "InputTag.Equip.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Unequip_Weapon, "InputTag.Unequip.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Inventory, "InputTag.Inventory");
	
	UE_DEFINE_GAMEPLAY_TAG(InputTag_KeyMustBeHeld, "InputTag.KeyMustBeHeld");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_KeyMustBeHeld_Block, "InputTag.KeyMustBeHeld.Block");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable, "InputTag.Toggleable");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable_TargetLock, "InputTag.Toggleable.TargetLock");

	/** Items Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Item_Weapon_StaffBase, "Item.Weapon.StaffBase");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EquipWeapon, "Player.Event.EquipWeapon");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Jump, "Player.Event.Jump");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Staff, "Player.Ability.Equip.Staff");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Staff, "Player.Ability.Unequip.Staff");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Jump, "Player.Ability.Jump");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Melee_Unarmed, "Player.Ability.Attack.Melee.Unarmed");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Falling, "Player.Status.Falling");
	
}
