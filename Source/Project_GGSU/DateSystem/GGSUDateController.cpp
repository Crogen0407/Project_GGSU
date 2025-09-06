// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUDateController.h"
#include "Components/DirectionalLightComponent.h"

FDateTime AGGSUDateController::Time = 0.0f;

// Sets default values
AGGSUDateController::AGGSUDateController()
{
	PrimaryActorTick.bCanEverTick = true;

	LightSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("LightRoot"));
	RootComponent = LightSceneComponent;

	SunDirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("SunDirectionalLight"));
	SunDirectionalLightComponent->SetWorldRotation(FRotator(-0.f, 0.f, 0.f));
	SunDirectionalLightComponent->AttachToComponent(LightSceneComponent, FAttachmentTransformRules::KeepWorldTransform);

	MoonDirectionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("MoonDirectionalLight"));
	MoonDirectionalLightComponent->SetWorldRotation(FRotator(180.f, 0.f, 0.f));
	MoonDirectionalLightComponent->AttachToComponent(LightSceneComponent, FAttachmentTransformRules::KeepWorldTransform);
	
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
	Time = FDateTime::UtcNow() + FTimespan::FromHours(CurrentCountry.GetIntValue());

	constexpr float OneHourAngle = 360.f/24.f;
	const float CurrentHourAngle = OneHourAngle * Time.GetHour();
	const float CurrentMinuteAngle =  OneHourAngle * Time.GetMinute() / 60.f;
	const float FinalAngle = CurrentHourAngle + CurrentMinuteAngle + 90.f;
	
	LightSceneComponent->SetWorldRotation(FRotator(FinalAngle, 45.f, 0.f));
}

