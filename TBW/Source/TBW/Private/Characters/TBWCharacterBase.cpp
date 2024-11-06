// DarrJorge All Rights Reserved.


#include "Characters/TBWCharacterBase.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "AbilitySystem/TBWAttributeSet.h"


ATBWCharacterBase::ATBWCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	TBWAbilitySystemComponent = CreateDefaultSubobject<UTBWAbilitySystemComponent>("TBWAbilitySystemComponent");
	TBWAttributeSet = CreateDefaultSubobject<UTBWAttributeSet>("TBWAttributeSet");
}

void ATBWCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (TBWAbilitySystemComponent)
	{
		TBWAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ATBWCharacterBase::GetAbilitySystemComponent() const
{
	return TBWAbilitySystemComponent;
}
