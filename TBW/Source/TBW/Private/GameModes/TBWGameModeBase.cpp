// DarrJorge All Rights Reserved.


#include "GameModes/TBWGameModeBase.h"

void ATBWGameModeBase::SetGameState(ETBWGameState InGameState)
{
	GameState = InGameState;
	GameStateChanged.Broadcast(InGameState);
}
