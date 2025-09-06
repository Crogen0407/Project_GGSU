// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/CropsSystem/GGSUCrop.h"
#include "GGSUCropDataAsset.h"
#include "DateSystem/GGSUDateController.h"

// Sets default values
AGGSUCrop::AGGSUCrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

  	for (int i = 0; i < 4; ++i)
  	{
		float Interval = 100.0f;
  	    FString CompName = FString::Printf(TEXT("MeshComp_%d"), i);
  		UStaticMeshComponent* MeshCompo = CreateDefaultSubobject<UStaticMeshComponent>(*CompName);
  		MeshCompo->SetupAttachment(RootComponent);
		MeshCompo->SetRelativeLocation(FVector((i % 2 - 0.5f) * Interval, (FMath::Floor(i / 2) - 0.5f) * Interval, 0.f));
  		MeshComponents.Add(MeshCompo);
  	}
}

void AGGSUCrop::Initialize(UGGSUCropDataAsset* CropDataAsset)
{
	CachedCropsDataAsset = CropDataAsset;
	SpawnTime = AGGSUDateController::GetTime();
	MeshCount = CropDataAsset->StaticMeshes.Max();
}

// Called every frame
void AGGSUCrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CachedCropsDataAsset == nullptr) return;
	else if (MeshCount == 0)
		Initialize(CachedCropsDataAsset);

	Age = AGGSUDateController::GetTime() - SpawnTime;

	UStaticMesh* CurrentMesh = GetCurrentStaticMesh();
	if (MeshComponents[0]->GetStaticMesh() != CurrentMesh)
	{
		for (int i = 0; i < 4; ++i)
		{
			MeshComponents[i]->SetStaticMesh(CurrentMesh);
		}
	}
}

UStaticMesh* AGGSUCrop::GetCurrentStaticMesh() const
{
	float Amount = Age.GetMinutes() / CachedCropsDataAsset->GrowthTime;	// 0~1
	int32 Index = FMath::Floor(MeshCount * Amount);
	Index = FMath::Clamp(Index, 0, MeshCount - 1);
	
	return CachedCropsDataAsset->StaticMeshes[Index];
}

