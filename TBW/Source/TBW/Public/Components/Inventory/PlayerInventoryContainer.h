// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Inventory/TBW_ItemsContainerBase.h"
#include "PlayerInventoryContainer.generated.h"


UCLASS()
class TBW_API UPlayerInventoryContainer : public UTBW_ItemsContainerBase
{
	GENERATED_BODY()

protected:

	virtual void HandleSlotDrop(UTBW_ItemsContainerBase* ContainerFrom, int32 IndexFrom, int32 IndexTo) override;
	
};
