// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/TBWWeaponBase.h"
#include "Types/TBW_StructTypes.h"
#include "TBWHeroWeapon.generated.h"


UCLASS()
class TBW_API ATBWHeroWeapon : public ATBWWeaponBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TBW|WeaponData")
	FWeaponData WeaponData;
	
};
