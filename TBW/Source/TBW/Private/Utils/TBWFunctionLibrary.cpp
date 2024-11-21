// DarrJorge All Rights Reserved.


#include "Utils/TBWFunctionLibrary.h"
#include "GameModes/TBWGameModeBase.h"

ATBWGameModeBase* UTBWFunctionLibrary::GetTBWGameModeBase(UObject* WorldContextObject)
{
	if (!GEngine) return nullptr;
	const auto* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;
	return Cast<ATBWGameModeBase>(World->GetAuthGameMode());
}
