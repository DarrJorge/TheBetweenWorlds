// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "Types/TBW_StructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"


UCLASS()
class TBW_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void InitStartupAbilities(UTBWAbilitySystemComponent* InASC, int32 ApplyLevel) override;

private:

	UPROPERTY(EditDefaultsOnly, Category="StartUpData|Abilities")
	TArray<FHeroAbilitySet> HeroAbilitySets;
	
};
