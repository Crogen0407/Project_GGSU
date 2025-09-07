#include "GGSUPlayerPawn.h"
#include "GGSUInputMapperComponent.h"
#include "GGSUPlayerMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGGSUPlayerPawn::AGGSUPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// Create a camera boom...
	CameraBoomComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	{
		CameraBoomComponent->SetupAttachment(RootComponent);
		CameraBoomComponent->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
		CameraBoomComponent->TargetArmLength = 800.f;
		CameraBoomComponent->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
		CameraBoomComponent->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	}
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	{
		CameraComponent->SetupAttachment(CameraBoomComponent, USpringArmComponent::SocketName);
		CameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	}

	MovementComponent = CreateDefaultSubobject<UGGSUPlayerMovementComponent>(TEXT("MovementComponent"));
	InputMapperComponent = CreateDefaultSubobject<UGGSUInputMapperComponent>(TEXT("InputMapper"));
}

void AGGSUPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AGGSUPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputMapperComponent->SetupPlayerInput(PlayerInputComponent);
}

// Called every frame
void AGGSUPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}