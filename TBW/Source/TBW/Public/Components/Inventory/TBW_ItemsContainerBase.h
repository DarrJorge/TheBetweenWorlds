// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "Types/TBW_StructTypes.h"
#include "Types/TBW_Enums.h"
#include "TBW_ItemsContainerBase.generated.h"


UCLASS()
class TBW_API UTBW_ItemsContainerBase : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UTBW_ItemsContainerBase();

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

private:
	bool TryFindEmptySlot(int& EmptySlotIndex);
};
