// DarrJorge All Rights Reserved.


#include "Components/Inventory/TBW_ItemsContainerBase.h"

UTBW_ItemsContainerBase::UTBW_ItemsContainerBase()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);
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
		InsertItemToSlot(EmptyIndex, NewItem);
	}
}

void UTBW_ItemsContainerBase::OnSlotDrop_Implementation(UTBW_ItemsContainerBase* ContainerFrom, int32 IndexFrom,
	int32 IndexTo)
{
	HandleSlotDrop(ContainerFrom, IndexFrom, IndexTo);
}

void UTBW_ItemsContainerBase::TransferItem(UTBW_ItemsContainerBase* NewContainer, int32 IndexFrom, int32 IndexTo)
{
	if (!NewContainer || !SlotIsEmpty(IndexTo)) return;

	FItemData OutItemData;
	if (TryGetSlotDataByIndex(IndexFrom,OutItemData))
	{
		NewContainer->InsertItemToSlot(IndexTo, OutItemData);
		ResetSlotDataByIndex(IndexFrom);
	}
}

void UTBW_ItemsContainerBase::HandleSlotDrop(UTBW_ItemsContainerBase* ContainerFrom, int32 IndexFrom, int32 IndexTo)
{
	// implementation in derived classes
}

bool UTBW_ItemsContainerBase::TryFindEmptySlot(int32& EmptySlotIndex) const
{
	EmptySlotIndex = Items.IndexOfByPredicate([](const FItemData& Item)
	{
		return Item.ItemID == 0;
	});
	
	return EmptySlotIndex != INDEX_NONE;
}

bool UTBW_ItemsContainerBase::SlotIsEmpty(int32 SlotIndex)
{
	return SlotIndex < Items.Num() && Items[SlotIndex].ItemID == 0;
}

bool UTBW_ItemsContainerBase::TryGetSlotDataByIndex(int32 SlotIndex, FItemData& OutSlotData)
{
	if (SlotIndex >= Items.Num()) return false;
	OutSlotData = Items[SlotIndex];
	return true;
}

void UTBW_ItemsContainerBase::InsertItemToSlot(int32 SlotIndex, const FItemData& NewItem)
{
	Items[SlotIndex] = NewItem;
	OnAddedItemToSlot.Broadcast(SlotIndex, NewItem);

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::MakeRandomColor(),
		FString(TEXT("Added item to inventory")));
}

void UTBW_ItemsContainerBase::ResetSlotDataByIndex(int32 SlotIndex)
{
	if (SlotIsEmpty(SlotIndex)) return;
	FItemData EmptyItem = FItemData();
	Items[SlotIndex] = EmptyItem;
	OnAddedItemToSlot.Broadcast(SlotIndex, EmptyItem);
}
