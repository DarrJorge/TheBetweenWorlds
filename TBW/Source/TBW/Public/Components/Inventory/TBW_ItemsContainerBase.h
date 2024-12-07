// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "Types/TBW_StructTypes.h"
#include "Types/TBW_Enums.h"
#include "TBW_ItemsContainerBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedItemToSlot, int32, Index, FItemData, ItemInfo);

UCLASS()
class TBW_API UTBW_ItemsContainerBase : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UTBW_ItemsContainerBase();

	UPROPERTY(BlueprintAssignable, Category="TBW|Inventory|Events")
	FOnAddedItemToSlot OnAddedItemToSlot;

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	TArray<FItemData> Items;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	EContainerType ContainerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory")
	int32 MaxAmountContainerSlots = 30;
	
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, Server, Reliable, Category="TBW|ItemsContainer")
	void AddItemTo(FItemData NewItem);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void OnSlotDrop(UTBW_ItemsContainerBase* ContainerFrom, int32 IndexFrom, int32 IndexTo);

	void TransferItem(UTBW_ItemsContainerBase* NewContainer, int32 IndexFrom, int32 IndexTo);

protected:

	virtual void HandleSlotDrop(UTBW_ItemsContainerBase* ContainerFrom, int32 IndexFrom, int32 IndexTo);

private:
	bool TryFindEmptySlot(int32& EmptySlotIndex) const;
	bool SlotIsEmpty(int32 SlotIndex);
	bool TryGetSlotDataByIndex(int32 SlotIndex, FItemData& OutSlotData);
	void InsertItemToSlot(int32 SlotIndex, const FItemData& NewItem);
	void ResetSlotDataByIndex(int32 SlotIndex);
};
