// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUDateController.h"
#include "Components/DirectionalLightComponent.h"

float AGGSUDateController::Time = 0.0f;

// Sets default values
AGGSUDateController::AGGSUDateController()
{
	PrimaryActorTick.bCanEverTick = true;

	DirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("DirectionalLight"));
	
	RootComponent = DirectionalLightComponent;

	AGGSUDateController::Time = 0.0f;
}

// Called when the game starts or when spawned
void AGGSUDateController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGGSUDateController::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	AGGSUDateController::Time += DeltaTime * 10;
	DirectionalLightComponent->SetWorldRotation(FRotator(AGGSUDateController::Time+90, 0, 0));
}

