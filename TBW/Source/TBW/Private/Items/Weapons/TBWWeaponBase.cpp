// DarrJorge All Rights Reserved.


#include "Items/Weapons/TBWWeaponBase.h"
#include "Components/BoxComponent.h"

ATBWWeaponBase::ATBWWeaponBase() : Super()
{
	PrimaryActorTick.bCanEverTick = false;
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>("WeaponCollisionBox");
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ATBWWeaponBase::OnCollisionBoxBeginOverlap);
	WeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ATBWWeaponBase::OnCollisionBoxEndOverlap);
}

void ATBWWeaponBase::SetWeaponCollision(bool bShouldEnable) const
{
	WeaponCollisionBox->SetCollisionEnabled(bShouldEnable ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
}

void ATBWWeaponBase::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ATBWWeaponBase::OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}



