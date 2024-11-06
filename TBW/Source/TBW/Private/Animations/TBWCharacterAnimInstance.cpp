// DarrJorge All Rights Reserved.


#include "Animations/TBWCharacterAnimInstance.h"
#include "Characters/TBWCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"


void UTBWCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ATBWCharacterBase>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComp = OwningCharacter->GetCharacterMovement();
	}
}

void UTBWCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComp) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComp->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}