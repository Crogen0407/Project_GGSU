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
	float OneHourAngle = 360.f/24.f;
	Time += DeltaTime * TimeSpeed;
	DirectionalLightComponent->SetWorldRotation(FRotator(OneHourAngle * Time + 90.f, 45.f, 0.f));
}

