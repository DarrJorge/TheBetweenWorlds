// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Types/TBW_Enums.h"
#include "TBWPlayerController.generated.h"


UCLASS()
class TBW_API ATBWPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	void OnGameStateChanged(ETBWGameState InGameState);
	
};
