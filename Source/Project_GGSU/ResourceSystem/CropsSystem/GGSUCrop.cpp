#include "ResourceSystem/CropsSystem/GGSUCrop.h"
#include "GGSUCropSeedDataAsset.h"
#include "DateSystem/GGSUDateManager.h"

// Sets default values
AGGSUCrop::AGGSUCrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

  	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
  	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
}

void AGGSUCrop::Initialize(UGGSUCropSeedDataAsset* CropSeed)
{
	CachedCropSeed = CropSeed;
	SpawnTime = UGGSUDateManager::GetTime();
	MeshCount = CropSeed->GetStaticMeshes().Num();
}

// Called every frame
void AGGSUCrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CachedCropSeed == nullptr) return;

	Age = UGGSUDateManager::GetTime() - SpawnTime;

	if (UStaticMesh* CurrentMesh = GetCurrentStaticMesh(); MeshComponent->GetStaticMesh() != CurrentMesh)
	{
		MeshComponent->SetStaticMesh(CurrentMesh);
	}

	if (IsCropFullyGrown())
	{
		// TODO : 반짝반짝
	}
}

bool AGGSUCrop::IsCropFullyGrown() const
{
	return Age.GetTotalMinutes() / CachedCropSeed->GetGrowthTime() >= 1.f;
}

UStaticMesh* AGGSUCrop::GetCurrentStaticMesh() const
{
	float Amount = Age.GetTotalMinutes() / CachedCropSeed->GetGrowthTime();	// 0~1
	int32 Index = FMath::Floor(MeshCount * Amount);
	Index = FMath::Clamp(Index, 0, MeshCount - 1);
	
	return CachedCropSeed->GetStaticMeshes()[Index];
}

