// DarrJorge All Rights Reserved.


#include "Characters/TBWHeroCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/TBWAbilitySystemComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "Components/Input/TBWEnhancedInputComponent.h"
#include "Components/Inventory/PlayerInventoryContainer.h"
#include "TBWGameplayTags.h"

ATBWHeroCharacter::ATBWHeroCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>("HeroCombatComponent");
	PlayerInventoryContainer = CreateDefaultSubobject<UPlayerInventoryContainer>("PlayerInventory");
}

void ATBWHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ATBWHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetController<APlayerController>()->GetLocalPlayer()))
	{
		SubSystem->AddMappingContext(InputConfigAsset->DefaultMappingContext, 0);

		if (UTBWEnhancedInputComponent* TBWInputComponent = Cast<UTBWEnhancedInputComponent>(PlayerInputComponent))
		{
			TBWInputComponent->BindNativeInputAction(InputConfigAsset, TBWGameplayTags::InputTag_Move,
				ETriggerEvent::Triggered, this, &ThisClass::OnInputMove);

			TBWInputComponent->BindNativeInputAction(InputConfigAsset, TBWGameplayTags::InputTag_Look,
				ETriggerEvent::Triggered, this, &ThisClass::OnInputLook);

			TBWInputComponent->BindNativeInputAction(InputConfigAsset, TBWGameplayTags::InputTag_Jump,
				ETriggerEvent::Started, this, &ThisClass::Jump);

			TBWInputComponent->BindAbilityInputAction(InputConfigAsset, this,
				&ATBWHeroCharacter::OnInputAbilityPressed, &ATBWHeroCharacter::OnInputAbilityReleased);
		}
		
	}
}

void ATBWHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(TBWAbilitySystemComponent);
		}
	}
}

void ATBWHeroCharacter::OnInputMove(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator MovementRotation = FRotator(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}
	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATBWHeroCharacter::OnInputLook(const FInputActionValue& Value)
{
	const FVector2D LookVector = Value.Get<FVector2D>();

	if (LookVector.X != 0) AddControllerYawInput(LookVector.X);
	if (LookVector.Y != 0) AddControllerPitchInput(LookVector.Y);
}

void ATBWHeroCharacter::OnInputAbilityPressed(FGameplayTag InputTag)
{
	TBWAbilitySystemComponent->OnAbilityInputPressed(InputTag);
}

void ATBWHeroCharacter::OnInputAbilityReleased(FGameplayTag InputTag)
{
	TBWAbilitySystemComponent->OnAbilityInputReleased(InputTag);
}

UCombatComponentBase* ATBWHeroCharacter::GetPawnCombatComponent() const
{
	return HeroCombatComponent;
}
