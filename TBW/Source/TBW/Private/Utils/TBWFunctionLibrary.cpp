// DarrJorge All Rights Reserved.


#include "Utils/TBWFunctionLibrary.h"
#include "Characters/TBWHeroCharacter.h"
#include "Components/Inventory/PlayerInventoryContainer.h"
#include "GameModes/TBWGameModeBase.h"

ATBWGameModeBase* UTBWFunctionLibrary::GetTBWGameModeBase(UObject* WorldContextObject)
{
	if (!GEngine) return nullptr;
	const auto* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;
	return Cast<ATBWGameModeBase>(World->GetAuthGameMode());
}

UPlayerInventoryContainer* UTBWFunctionLibrary::GetInventoryFromController(const APlayerController* PlayerController)
{
	if (!PlayerController) return nullptr;
	const ATBWHeroCharacter* Character = Cast<ATBWHeroCharacter>(PlayerController->GetPawn());
	if (!Character) return nullptr;
	return Character->FindComponentByClass<UPlayerInventoryContainer>();
}
