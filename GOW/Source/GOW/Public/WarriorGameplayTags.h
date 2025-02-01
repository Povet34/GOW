
#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	/** Input Tag **/
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

	/** Player Tag **/
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Heavy_Light_Axe);

	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);

	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	/** Enemy Tag **/
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);

	/** Shared Tag **/
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);
}