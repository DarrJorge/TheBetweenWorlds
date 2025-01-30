// DarrJorge All Rights Reserved.


#include "UI/Widgets/TBW_InventoryActivatableWidget.h"
#include "CommonButtonBase.h"
#include "Controllers/TBWPlayerController.h"


void UTBW_InventoryActivatableWidget::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	if (GetWorld())
	{
		if (auto* PC = Cast<ATBWPlayerController>(GetWorld()->GetFirstPlayerController()))
		{
			PC->OnOpenInventory();
		}
	}
}
