// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TBW_Enums.generated.h"

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	Common = 0,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

UENUM(BlueprintType)
enum class EItemType: uint8
{
	Junk = 0,
	Resource,
	Equippable,
	Armor,
	Consumable,
	Buildable
};

UENUM(BlueprintType)
enum class EArmorType: uint8
{
	None = 0,
	Helmet,
	Chest,
	Pants,
	Boots,
	Backpack
};

UENUM(BlueprintType)
enum class EContainerType: uint8
{
	Inventory = 0,
	HotBar,
	Storage,
	Armor
};

UENUM()
enum class ETBWGameState: uint8
{
	GameProgress = 0 UMETA(DisplayName="GameProgress"),
	ShowInventory UMETA(DisplayName="ShowInventory"),
	PauseMenu UMETA(DisplayName="PauseMenu")
};