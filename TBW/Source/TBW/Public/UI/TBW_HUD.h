// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Types/TBW_Enums.h"
#include "TBW_HUD.generated.h"

class UTBW_MainLayoutWidget;

UCLASS()
class TBW_API ATBW_HUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UTBW_MainLayoutWidget> MainLayoutHUDClass;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UTBW_MainLayoutWidget> MainLayoutHUD;

	UFUNCTION()
	void OnGameStateChanged(ETBWGameState InGameState);
	
};
