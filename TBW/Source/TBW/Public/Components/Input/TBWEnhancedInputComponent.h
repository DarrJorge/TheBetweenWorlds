// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "TBWEnhancedInputComponent.generated.h"


UCLASS()
class TBW_API UTBWEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class T, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent,
		T* ContextObject, CallbackFunc Func);

	template<class T, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InputConfig, T* ContextObject, CallbackFunc InputPressedFunc,
		CallbackFunc InputReleasedFunc);
	
};

template <class T, typename CallbackFunc>
void UTBWEnhancedInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InputConfig,
	const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, T* ContextObject, CallbackFunc Func)
{
	checkf(InputConfig, TEXT("Input config data asset is null, can't proceed with binding."));

	if (UInputAction* FoundAction = InputConfig->FindNativeInputActionByTag(InputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}	
}

template <class T, typename CallbackFunc>
void UTBWEnhancedInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InputConfig, T* ContextObject,
	CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc)
{
	checkf(InputConfig, TEXT("Input config data asset is null, can't proceed with binding."));

	for (const FTBWInputActionConfig& AbilityInputAction : InputConfig->AbilityInputActions)
	{
		if (!AbilityInputAction.IsValid()) continue;
		
		BindAction(AbilityInputAction.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, AbilityInputAction.InputTag);
		BindAction(AbilityInputAction.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, AbilityInputAction.InputTag);
	}
}
