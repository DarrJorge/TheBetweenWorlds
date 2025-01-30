// DarrJorge All Rights Reserved.


#include "UI/TBW_HUD.h"
#include "Controllers/TBWPlayerController.h"
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

	if (const auto PC = Cast<ATBWPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PC->OnGameStateChanged.AddDynamic(this, &ThisClass::OnGameStateChanged);
	}
}

void ATBW_HUD::OnGameStateChanged(ETBWGameState InGameState)
{
	MainLayoutHUD->SelectWidget(InGameState);
}
