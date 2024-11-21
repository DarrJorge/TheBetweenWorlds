// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Types/TBW_Enums.h"
#include "TBWGameModeBase.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameStateChangedSignature, ETBWGameState);

UCLASS()
class TBW_API ATBWGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	FOnGameStateChangedSignature GameStateChanged;
	
	void SetGameState(ETBWGameState InGameState);

private:
	ETBWGameState GameState;
	
};
