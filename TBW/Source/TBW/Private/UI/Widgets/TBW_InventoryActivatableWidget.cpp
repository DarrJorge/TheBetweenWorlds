// DarrJorge All Rights Reserved.


#include "UI/Widgets/TBW_InventoryActivatableWidget.h"
#include "CommonButtonBase.h"
#include "GameModes/TBWGameModeBase.h"
#include "Utils/TBWFunctionLibrary.h"


void UTBW_InventoryActivatableWidget::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();
	
	if (auto* GameMode = UTBWFunctionLibrary::GetTBWGameModeBase(GetOwningPlayer()))
	{
		GameMode->SetGameState(ETBWGameState::GameProgress);
	}
}
