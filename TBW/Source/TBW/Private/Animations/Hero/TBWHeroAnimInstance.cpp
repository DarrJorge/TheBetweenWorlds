// DarrJorge All Rights Reserved.


#include "Animations/Hero/TBWHeroAnimInstance.h"
//#include "Characters/"

void UTBWHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		//OwningHeroCharacter = Cast<ATBWHeroCharacter>(OwningCharacter);
	}
}

void UTBWHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;
		bShouldEnterRelaxState = IdleElpasedTime >= EnterRelaxStateThreshold;
	}
}
