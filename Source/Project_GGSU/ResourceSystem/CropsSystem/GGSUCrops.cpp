// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/CropsSystem/GGSUCrops.h"
#include "GGSUCropDataAsset.h"
#include "DateSystem/GGSUDateController.h"

// Sets default values
AGGSUCrops::AGGSUCrops()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

}

void AGGSUCrops::Initialize(UGGSUCropDataAsset* CropDataAsset)
{
	CachedCropsDataAsset = CropDataAsset;
	SpawnTime = AGGSUDateController::GetTime();
	MeshCount = CropDataAsset->StaticMeshes.Max();
}

// Called every frame
void AGGSUCrops::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CachedCropsDataAsset == nullptr) return;
	
	Age = FMath::Clamp(AGGSUDateController::GetTime() - SpawnTime, 0., CachedCropsDataAsset->GrowthTime);

	UStaticMesh* CurrentMesh = GetCurrentStaticMesh();
	if (MeshComp->GetStaticMesh() != CurrentMesh)
	{		
		MeshComp->SetStaticMesh(CurrentMesh);
	}
}

UStaticMesh* AGGSUCrops::GetCurrentStaticMesh() const
{
	float Amount = Age / CachedCropsDataAsset->GrowthTime;	// 0~1
	int32 Index = FMath::Floor(MeshCount * Amount);
	Index = FMath::Clamp(Index, 0, MeshCount - 1);

	UE_LOG(LogTemp, Warning, TEXT("%d 아아아아아아아아아아아아아아아악"), Index);
	return CachedCropsDataAsset->StaticMeshes[Index];
}

