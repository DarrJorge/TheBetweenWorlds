// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/TBW_ItemBase.h"
#include "TBWWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class TBW_API ATBWWeaponBase : public ATBW_ItemBase
{
	GENERATED_BODY()
	
public:	
	ATBWWeaponBase();

	void SetWeaponCollision(bool bShouldEnable) const;

	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TBW|Weapon")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TBW|Weapon")
	UBoxComponent* WeaponCollisionBox;

	UFUNCTION()
	virtual void OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
