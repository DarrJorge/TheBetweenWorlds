// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Types/TBW_Enums.h"
#include "TBWPlayerController.generated.h"


class UInputAction;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChangedDelegate, ETBWGameState, GameState);

UCLASS()
class TBW_API ATBWPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATBWPlayerController();

	UPROPERTY(BlueprintAssignable)
	FOnGameStateChangedDelegate OnGameStateChanged;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	UInputMappingContext* UIMappingContext;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	UInputAction* PauseAction;
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	UInputAction* InventoryOpenAction;
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	void ToggleInputMode(ETBWGameState InGameState, bool bSetPause);
	void ToggleGamePause();
	void OnOpenInventory();

	bool bInPause{false};
	ETBWGameState GameState;

	friend class UTBW_InventoryActivatableWidget;
	
};
