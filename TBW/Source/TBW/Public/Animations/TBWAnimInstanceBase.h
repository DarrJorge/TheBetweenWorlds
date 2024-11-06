// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "TBWAnimInstanceBase.generated.h"


UCLASS()
class TBW_API UTBWAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable, meta=(BlueprintThreadSafe))
	bool DoesOwnerGameplayTag(FGameplayTag InTag);
	
	
};
