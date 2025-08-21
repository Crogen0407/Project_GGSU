// Fill out your copyright notice in the Description page of Project Settings.


#include "DateController.h"
#include "Components/DirectionalLightComponent.h"

// Sets default values
ADateController::ADateController()
{
	PrimaryActorTick.bCanEverTick = true;

	DirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("DirectionalLight"));
	
	RootComponent = DirectionalLightComponent;
}

// Called when the game starts or when spawned
void ADateController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADateController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime * 10;
	DirectionalLightComponent->SetWorldRotation(FRotator(Time+90, 0, 0));
}

