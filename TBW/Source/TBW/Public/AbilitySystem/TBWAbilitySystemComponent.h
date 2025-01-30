// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Types/TBW_StructTypes.h"
#include "TBWAbilitySystemComponent.generated.h"


UCLASS()
class TBW_API UTBWAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	void OnAbilityInputPressed(const FGameplayTag& InputTag);
	void OnAbilityInputReleased(const FGameplayTag& InputTag);

	void GrantAbilities(const TArray<TSubclassOf<UGameplayAbility>> InGrantAbilities, int32 ApplyLevel = 1);
	void GrantGameplayEffects(const TArray<TSubclassOf<UGameplayEffect>> InGrantEffects, int32 ApplyLevel = 1);

	void GrantAbilityWithTag(TSubclassOf<UGameplayAbility> InAbility, const FGameplayTag& InTag, int32 ApplyLevel = 1);
	
	UFUNCTION(BlueprintCallable, Category="TBW|AbilitySystem", meta=(InLevel="1"))
	void GrantCharacterWeaponAbilities(const TArray<FHeroAbilitySet>& DefaultWeaponAbilities, int32 InLevel,
		TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category="TBW|AbilitySystem")
	void RemoveGrantedCharacterWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category="TBW|AbilitySystem")
	bool TryActivateAbilityByTag(const FGameplayTag& InAbilityTag);
	
};
