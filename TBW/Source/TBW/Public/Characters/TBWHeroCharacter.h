// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Characters/TBWCharacterBase.h"
#include "Types/TBW_Enums.h"
#include "TBWHeroCharacter.generated.h"


class UGameplayAbility;
class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
class UHeroCombatComponent;
class UPlayerInventoryContainer;
struct FInputActionValue;

DECLARE_MULTICAST_DELEGATE(FOnInventoryEventDelegate);


UCLASS()
class TBW_API ATBWHeroCharacter : public ATBWCharacterBase
{
	GENERATED_BODY()

public:
	ATBWHeroCharacter();

	FOnInventoryEventDelegate InventoryAction;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UHeroCombatComponent* HeroCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UPlayerInventoryContainer* PlayerInventoryContainer;
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TBW|Input", meta=(AllowPrivateAccess="true"))
	UDataAsset_InputConfig* InputConfigAsset;

	bool bShowInventory = false;
	
	void OnInputMove(const FInputActionValue& Value);
	void OnInputLook(const FInputActionValue& Value);

	void OnInputAbilityPressed(FGameplayTag InputTag);
	void OnInputAbilityReleased(FGameplayTag InputTag);

	bool TryLoadGrantedAbilities(TArray<TSubclassOf<UGameplayAbility>>& OutGrantedAbilities);
	void SaveGrantedAbility(TSubclassOf<UGameplayAbility> InAbility);

public:

	//~ Begin IPawnCombatInterface Interface
	virtual UCombatComponentBase* GetPawnCombatComponent() const override;
	
	void ResetMovementInput();

	UFUNCTION(BlueprintCallable)
	void OnItemMoved(EContainerType ContainerTypeFrom, EContainerType ContainerTypeTarget, int32 IndexFrom, int32 IndexTarget);
};
