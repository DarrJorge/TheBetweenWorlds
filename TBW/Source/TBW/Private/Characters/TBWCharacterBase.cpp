// DarrJorge All Rights Reserved.


#include "Characters/TBWCharacterBase.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "AbilitySystem/TBWAttributeSet.h"
#include "Engine/AssetManager.h"


ATBWCharacterBase::ATBWCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	TBWAbilitySystemComponent = CreateDefaultSubobject<UTBWAbilitySystemComponent>("TBWAbilitySystemComponent");
	TBWAttributeSet = CreateDefaultSubobject<UTBWAttributeSet>("TBWAttributeSet");
}

void ATBWCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void ATBWCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

UAbilitySystemComponent* ATBWCharacterBase::GetAbilitySystemComponent() const
{
	return TBWAbilitySystemComponent;
}

UCombatComponentBase* ATBWCharacterBase::GetPawnCombatComponent() const
{
	return nullptr;
}

void ATBWCharacterBase::InitAbilityActorInfo()
{
	if (TBWAbilitySystemComponent)
	{
		TBWAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
