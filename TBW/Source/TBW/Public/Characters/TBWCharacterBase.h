// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "TBWCharacterBase.generated.h"

class UTBWAbilitySystemComponent;
class UTBWAttributeSet;
class UDataAsset_StartUpDataBase;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;
	
	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

public:

	//~ Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//~ Begin IPawnCombatInterface Interface
	virtual UCombatComponentBase* GetPawnCombatComponent() const override;

private:
	void InitAbilityActorInfo();
	
};
