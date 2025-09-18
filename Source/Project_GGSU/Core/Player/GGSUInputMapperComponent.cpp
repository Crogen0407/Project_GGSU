#include "GGSUInputMapperComponent.h"
#include "GGSUPlayerController.h"
#include "GGSUPlayerMovementComponent.h"
#include "MathUtil.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/SpringArmComponent.h"

UGGSUInputMapperComponent::UGGSUInputMapperComponent()
{
	bAllowConcurrentTick = true;
}

void UGGSUInputMapperComponent::BeginPlay()
{
	Super::BeginPlay();

	CachedMovementComponent = GetOwner()->GetComponentByClass<UGGSUPlayerMovementComponent>();
	CachedCameraBoomComponent = GetOwner()->GetComponentByClass<USpringArmComponent>();

	if (AGGSUPlayerController* PC = Cast<AGGSUPlayerController>(GetWorld()->GetFirstPlayerController()))
		IsEnable = &PC->IsEnable;
	
	if (CachedMovementComponent == nullptr)
		UE_LOG(LogTemp, Error, TEXT("In BeginPlay, CachedMovementComponent is NULL!"));

	if (CachedCameraBoomComponent == nullptr)
		UE_LOG(LogTemp, Error, TEXT("In BeginPlay, CachedCameraBoomComponent is NULL!"));
}

void UGGSUInputMapperComponent::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	InitializeDefaultPawnInputBindings();
	PlayerInputComponent->BindAxis("PlayerPawn_MoveForward", this, &UGGSUInputMapperComponent::MoveForward);
	PlayerInputComponent->BindAxis("PlayerPawn_MoveRight", this, &UGGSUInputMapperComponent::MoveRight);
	PlayerInputComponent->BindAxis("PlayerPawn_MoveCameraDistance", this, &UGGSUInputMapperComponent::MoveCameraDistance);
}

void UGGSUInputMapperComponent::InitializeDefaultPawnInputBindings()
{
	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveForward", EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveForward", EKeys::Up, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveForward", EKeys::Down, -1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveRight", EKeys::Left, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveRight", EKeys::Right, 1.f));
		
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerPawn_MoveCameraDistance", EKeys::MouseWheelAxis, 1.f));
	}
}

void UGGSUInputMapperComponent::MoveForward(float Val)
{
	if (*IsEnable == false) return;
	if (CachedMovementComponent)
		CachedMovementComponent->MoveForward(Val);
}

void UGGSUInputMapperComponent::MoveRight(float Val)
{
	if (*IsEnable == false) return;
	if (CachedMovementComponent)
		CachedMovementComponent->MoveRight(Val);
}

void UGGSUInputMapperComponent::MoveCameraDistance(float Val)
{
	if (*IsEnable == false) return;
	if (CachedCameraBoomComponent)
		CachedCameraBoomComponent->TargetArmLength = FMathf::Clamp(CachedCameraBoomComponent->TargetArmLength - Val * 100, 250.f, 5000.f);
}
