// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animations/TBWCharacterAnimInstance.h"
#include "TBWHeroAnimInstance.generated.h"

//class ATBWHeroCharacter;

UCLASS()
class TBW_API UTBWHeroAnimInstance : public UTBWCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|References")
	//ATBWHeroCharacter* OwningHeroCharacter;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElpasedTime = 0.f;
	
};
