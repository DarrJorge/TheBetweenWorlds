// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animations/TBWAnimInstanceBase.h"
#include "TBWHeroLinkedAnimLayer.generated.h"

class UTBWHeroAnimInstance;

UCLASS()
class TBW_API UTBWHeroLinkedAnimLayer : public UTBWAnimInstanceBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, meta=(NotBlueprintThreadSafe))
	UTBWHeroAnimInstance* GetHeroAnimInstance() const;
	
};
