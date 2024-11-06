// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animations/TBWAnimInstanceBase.h"
#include "TBWCharacterAnimInstance.generated.h"


class UCharacterMovementComponent;
class ATBWCharacterBase;


UCLASS()
class TBW_API UTBWCharacterAnimInstance : public UTBWAnimInstanceBase
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float LocomotionDirection;

	UPROPERTY()
	ATBWCharacterBase* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComp;
	
};
