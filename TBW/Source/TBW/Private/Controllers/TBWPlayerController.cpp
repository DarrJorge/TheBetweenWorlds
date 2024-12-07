// DarrJorge All Rights Reserved.


#include "Controllers/TBWPlayerController.h"
#include "Characters/TBWHeroCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameModes/TBWGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogTBWPlayerController, All, All);

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
		UE_LOG(LogTBWPlayerController, Warning, TEXT("Choose Game Progress state"));
		SetPawnInputMode(true);
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	else
	{
		UE_LOG(LogTBWPlayerController, Warning, TEXT("Choose not Game Progress state"));
		SetPawnInputMode(false);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}

void ATBWPlayerController::SetPawnInputMode(bool bEnable)
{
	if (!GetPawn() || !GetCharacter()) return;

	ATBWHeroCharacter* HeroCharacter = Cast<ATBWHeroCharacter>(GetCharacter());
	if (!HeroCharacter) return;
	HeroCharacter->GetCharacterMovement()->StopMovementImmediately();
	HeroCharacter->GetCharacterMovement()->Velocity = FVector::ZeroVector;
	HeroCharacter->ResetMovementInput();
	bEnable ? GetPawn()->EnableInput(this) : GetPawn()->DisableInput(this);
}
