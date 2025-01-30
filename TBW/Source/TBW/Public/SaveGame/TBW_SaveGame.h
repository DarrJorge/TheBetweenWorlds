// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TBW_SaveGame.generated.h"


class UGameplayAbility;

UCLASS()
class TBW_API UTBW_SaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, Category="SaveData")
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;
};
