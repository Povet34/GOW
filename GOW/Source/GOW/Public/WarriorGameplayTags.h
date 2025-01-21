
#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	/** Input Tag **/
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	/** Player Tag **/
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	GOW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}