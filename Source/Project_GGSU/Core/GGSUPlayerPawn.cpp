// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUPlayerPawn.h"

#include "Camera/CameraComponent.h"

// Sets default values
AGGSUPlayerPawn::AGGSUPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("StaticMesh"));
}

// Called when the game starts or when spawned
void AGGSUPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGSUPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGGSUPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

