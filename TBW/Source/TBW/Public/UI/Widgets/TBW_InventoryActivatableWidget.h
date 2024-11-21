// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "TBW_InventoryActivatableWidget.generated.h"

class UCommonButtonBase;

UCLASS()
class TBW_API UTBW_InventoryActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnDeactivated() override;
	
};
