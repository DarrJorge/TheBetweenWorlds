// DarrJorge All Rights Reserved.


#include "GameModes/TBWGameModeBase.h"

void ATBWGameModeBase::SetGameState(ETBWGameState InGameState)
{
	if (GameState == InGameState) return;
	GameState = InGameState;
	GameStateChanged.Broadcast(InGameState);
}
