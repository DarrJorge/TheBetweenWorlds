// DarrJorge All Rights Reserved.


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const auto& NativeInputAction : NativeInputActions)
	{
		if (NativeInputAction.InputTag.MatchesTagExact(InputTag))
		{
			return NativeInputAction.InputAction;
		}
	}
	return nullptr;
}
