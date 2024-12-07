// DarrJorge All Rights Reserved.


#include "UI/Widgets/TBW_InventoryActivatableWidget.h"
#include "CommonButtonBase.h"
#include "GameModes/TBWGameModeBase.h"
#include "Utils/TBWFunctionLibrary.h"


void UTBW_InventoryActivatableWidget::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	if (GetWorld())
	{
		if (auto* GameMode = Cast<ATBWGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->SetGameState(ETBWGameState::GameProgress);
		}
	}
}
