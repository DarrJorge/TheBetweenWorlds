// DarrJorge All Rights Reserved.


#include "Components/Inventory/PlayerInventoryContainer.h"

void UPlayerInventoryContainer::HandleSlotDrop(UTBW_ItemsContainerBase* ContainerFrom, int32 IndexFrom, int32 IndexTo)
{
	Super::HandleSlotDrop(ContainerFrom, IndexFrom, IndexTo);

	if (!ContainerFrom) return;
	if (ContainerFrom == this && IndexFrom == IndexTo) return;

	ContainerFrom->TransferItem(this, IndexFrom, IndexTo);
}
