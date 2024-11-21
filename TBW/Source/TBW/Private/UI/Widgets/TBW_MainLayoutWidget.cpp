// DarrJorge All Rights Reserved.


#include "UI/Widgets/TBW_MainLayoutWidget.h"

void UTBW_MainLayoutWidget::SelectWidget(ETBWGameState InGameState)
{
	switch (InGameState)
	{
	case ETBWGameState::GameProgress:
		bGameInventoryLayoutActive = false;
		break;
		
	case ETBWGameState::ShowInventory:
		bGameInventoryLayoutActive = !bGameInventoryLayoutActive;
		
		if (bGameInventoryLayoutActive)
		{
			PushGameInventoryHUD();
		}
		break;
		
	default: ;
	}
}
