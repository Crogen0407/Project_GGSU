// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/GGSUCrops.h"

// Sets default values
AGGSUCrops::AGGSUCrops()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGGSUCrops::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("%s"), *CropsDataAsset->Name.ToString());
}

// Called every frame
void AGGSUCrops::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

