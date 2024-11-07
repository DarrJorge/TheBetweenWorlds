// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "CombatComponentBase.generated.h"

class ATBWWeaponBase;


UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	EquippedWeapon,
	LeftHand,
	RightHand
};

UCLASS()
class TBW_API UCombatComponentBase : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category="TBW|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category="TBW|Combat")
	void RegisterWeapon(FGameplayTag InWeaponTag, ATBWWeaponBase* InWeapon, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category="TBW|Combat")
	ATBWWeaponBase* GetCarriedWeaponByTag(FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category="TBW|Combat")
	ATBWWeaponBase* GetCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category="TBW|Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::EquippedWeapon);

	UFUNCTION(BlueprintCallable, Category="TBW|Combat")
	float GetCurrentEquippedWeaponDamageAtLevel(float InLevel) const;

protected:
	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);

private:
	TMap<FGameplayTag, ATBWWeaponBase*> CarriedWeaponMap;
};
