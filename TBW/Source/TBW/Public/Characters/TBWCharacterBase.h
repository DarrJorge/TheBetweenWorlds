// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "TBWCharacterBase.generated.h"

class UTBWAbilitySystemComponent;
class UTBWAttributeSet;

UCLASS()
class TBW_API ATBWCharacterBase : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface
{
	GENERATED_BODY()

public:
	ATBWCharacterBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	UTBWAbilitySystemComponent* TBWAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	UTBWAttributeSet* TBWAttributeSet;
	
	virtual void PossessedBy(AController* NewController) override;

public:

	//~ Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
};
