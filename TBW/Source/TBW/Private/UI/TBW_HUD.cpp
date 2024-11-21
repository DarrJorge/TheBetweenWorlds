// DarrJorge All Rights Reserved.


#include "UI/TBW_HUD.h"
#include "GameModes/TBWGameModeBase.h"
#include "UI/Widgets/TBW_MainLayoutWidget.h"

void ATBW_HUD::BeginPlay()
{
	Super::BeginPlay();

	check(GetWorld());

	if (GetNetMode() != NM_DedicatedServer)
	{
		MainLayoutHUD = CreateWidget<UTBW_MainLayoutWidget>(GetWorld(), MainLayoutHUDClass);
		check(MainLayoutHUD);
		MainLayoutHUD->AddToViewport();
		MainLayoutHUD->PushDefaultHUD();
	}

	if (const auto GameMode = Cast<ATBWGameModeBase>(GetWorld()->GetAuthGameMode()))
	{
		GameMode->GameStateChanged.AddUObject(this, &ThisClass::OnGameStateChanged);
	}
}

void ATBW_HUD::OnGameStateChanged(ETBWGameState InGameState) const
{
	MainLayoutHUD->SelectWidget(InGameState);
}
