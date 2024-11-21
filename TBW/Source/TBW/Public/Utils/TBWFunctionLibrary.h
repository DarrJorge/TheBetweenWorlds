// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TBWFunctionLibrary.generated.h"

class ATBWGameModeBase;

UCLASS()
class TBW_API UTBWFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static ATBWGameModeBase* GetTBWGameModeBase(UObject* WorldContextObject);
	
};
