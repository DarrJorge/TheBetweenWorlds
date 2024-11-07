// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TBWGameplayAbility.generated.h"

class UTBWAbilitySystemComponent;
class UCombatComponentBase;

UENUM(BlueprintType)
enum class ETBWAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};


UCLASS()
class TBW_API UTBWGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="TBW|Ability")
	ETBWAbilityActivationPolicy AbilityActivationPolicy = ETBWAbilityActivationPolicy::OnTriggered;

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	UFUNCTION(BlueprintPure, Category="Arch|Ability")
	UCombatComponentBase* GetCombatComponentBaseFromActorInfo() const;
	
	UFUNCTION(BlueprintPure, Category="Arch|Ability")
	UTBWAbilitySystemComponent* GetTBWAbilitySystemComponentFromActorInfo() const;
	
};
