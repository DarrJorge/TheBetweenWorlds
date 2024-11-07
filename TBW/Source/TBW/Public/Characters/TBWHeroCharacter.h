// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Characters/TBWCharacterBase.h"
#include "TBWHeroCharacter.generated.h"


class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
class UHeroCombatComponent;
struct FInputActionValue;


UCLASS()
class TBW_API ATBWHeroCharacter : public ATBWCharacterBase
{
	GENERATED_BODY()

public:
	ATBWHeroCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UHeroCombatComponent* HeroCombatComponent;
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TBW|Input", meta=(AllowPrivateAccess="true"))
	UDataAsset_InputConfig* InputConfigAsset;

	void OnInputMove(const FInputActionValue& Value);
	void OnInputLook(const FInputActionValue& Value);

	void OnInputAbilityPressed(FGameplayTag InputTag);
	void OnInputAbilityReleased(FGameplayTag InputTag);

public:

	//~ Begin IPawnCombatInterface Interface
	virtual UCombatComponentBase* GetPawnCombatComponent() const override;
	
};
