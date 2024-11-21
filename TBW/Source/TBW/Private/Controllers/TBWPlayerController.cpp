// DarrJorge All Rights Reserved.


#include "Controllers/TBWPlayerController.h"
#include "GameModes/TBWGameModeBase.h"

void ATBWPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		if (const auto GameMode = Cast<ATBWGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->GameStateChanged.AddUObject(this, &ThisClass::OnGameStateChanged);
		}
	}
}

void ATBWPlayerController::OnGameStateChanged(ETBWGameState InGameState)
{
	if (InGameState == ETBWGameState::GameProgress)
	{
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}
