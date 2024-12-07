// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TBWFunctionLibrary.generated.h"

class UPlayerInventoryContainer;
class ATBWGameModeBase;

UCLASS()
class TBW_API UTBWFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="TBW|Utils")
	static ATBWGameModeBase* GetTBWGameModeBase(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TBW|Utils")
	static UPlayerInventoryContainer* GetInventoryFromController(const APlayerController* PlayerController);
	
};
