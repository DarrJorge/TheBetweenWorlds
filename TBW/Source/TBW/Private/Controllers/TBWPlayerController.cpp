// DarrJorge All Rights Reserved.


#include "Controllers/TBWPlayerController.h"
#include "Characters/TBWHeroCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

DEFINE_LOG_CATEGORY_STATIC(LogTBWPlayerController, All, All);

ATBWPlayerController::ATBWPlayerController() : Super()
{
	PrimaryActorTick.bTickEvenWhenPaused = true;
}

void ATBWPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(UIMappingContext, 1);
	}

	if (PauseAction)
	{
		PauseAction->bConsumeInput = false;
		PauseAction->bTriggerWhenPaused = true;
	}

	if (InventoryOpenAction)
	{
		InventoryOpenAction->bConsumeInput = false;
		InventoryOpenAction->bTriggerWhenPaused = true;
	}
}

void ATBWPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &ThisClass::ToggleGamePause);
		EnhancedInputComponent->BindAction(InventoryOpenAction, ETriggerEvent::Started, this, &ThisClass::OnOpenInventory);
	}
}

void ATBWPlayerController::ToggleInputMode(ETBWGameState InGameState, bool bSetPause)
{
	bInPause = bSetPause;
	SetPause(bInPause);
	
	GameState = InGameState;
	bShowMouseCursor = bInPause;

	if (bInPause)
	{
		SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
	}
	else
	{
		SetInputMode(FInputModeGameOnly());
	}

	OnGameStateChanged.Broadcast(GameState);
}

void ATBWPlayerController::ToggleGamePause()
{
	UE_LOG(LogTBWPlayerController, Warning, TEXT("Toggle gamePause! bInPause: %i state: %i"), bInPause, GameState);
	ToggleInputMode(ETBWGameState::PauseMenu, !(bInPause && GameState == ETBWGameState::PauseMenu));
}

void ATBWPlayerController::OnOpenInventory()
{
	UE_LOG(LogTBWPlayerController, Warning, TEXT("Toggle inventory! bInPause: %i state: %i"), bInPause, GameState);
	ToggleInputMode(ETBWGameState::ShowInventory, !(bInPause && GameState == ETBWGameState::ShowInventory));
}
