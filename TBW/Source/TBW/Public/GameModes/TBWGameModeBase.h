// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Types/TBW_Enums.h"
#include "TBWGameModeBase.generated.h"


UCLASS()
class TBW_API ATBWGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	void SetGameState(ETBWGameState InGameState);

private:
	ETBWGameState GameState;
	
};
