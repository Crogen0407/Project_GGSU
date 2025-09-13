// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUDateController.h"

#include "GGSUDateManager.h"


// Sets default values
AGGSUDateController::AGGSUDateController()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootSceneComponent;
	
	LightSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Lights"));
	LightSceneComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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
	Time = UGGSUDateManager::GetTime();
	
	constexpr float OneHourAngle = 360.f/24.f;
	const float CurrentHourAngle = OneHourAngle * Time.GetHour();
	const float CurrentMinuteAngle =  OneHourAngle * Time.GetMinute() / 60.f;
	const float FinalAngle = CurrentHourAngle + CurrentMinuteAngle + 90.f;

	if (LightSceneComponent)
		LightSceneComponent->SetWorldRotation(FRotator(FinalAngle, 45.f, 0.f));

	UGGSUDateManager::CurrentDay = FinalAngle >= 180.f && FinalAngle <= 360.f ? EDay::Day : EDay::Night;
}

