// DarrJorge All Rights Reserved.


#include "Animations/Hero/TBWHeroLinkedAnimLayer.h"
#include "Animations/Hero/TBWHeroAnimInstance.h"

UTBWHeroAnimInstance* UTBWHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UTBWHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
