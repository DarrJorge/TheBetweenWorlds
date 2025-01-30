// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"


class UGameplayAbility;
class UTBWAbilitySystemComponent;
class UGameplayEffect;
class UTBWGameplayAbility;

UCLASS()
class TBW_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	
	virtual void InitStartupAbilities(UTBWAbilitySystemComponent* InASC, int32 ApplyLevel = 1);

protected:

	UPROPERTY(EditDefaultsOnly, Category="StartUpData|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartUpData|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartUpData|Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartUpGameplayEffects;
	
};
