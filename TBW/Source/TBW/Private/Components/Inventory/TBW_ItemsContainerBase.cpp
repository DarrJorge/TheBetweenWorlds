// DarrJorge All Rights Reserved.


#include "Components/Inventory/TBW_ItemsContainerBase.h"

UTBW_ItemsContainerBase::UTBW_ItemsContainerBase()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTBW_ItemsContainerBase::BeginPlay()
{
	Super::BeginPlay();

	Items.SetNum(MaxAmountContainerSlots);
}

void UTBW_ItemsContainerBase::AddItemTo_Implementation(FItemData NewItem)
{
	int EmptyIndex;
	
	if (TryFindEmptySlot(EmptyIndex))
	{
		Items[EmptyIndex] = NewItem;

		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::MakeRandomColor(),
			FString(TEXT("Added item to inventory")));
	}
}

bool UTBW_ItemsContainerBase::TryFindEmptySlot(int& EmptySlotIndex)
{
	EmptySlotIndex = 0;

	for (const FItemData& Item : Items)
	{
		if (Item.ItemID == 0)
		{
			return true;
		}
		EmptySlotIndex++;
	}
	return false;
}