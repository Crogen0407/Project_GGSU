#include "ResourceSystem/CropsSystem/GGSUCropsGenerator.h"
#include "GGSUCrop.h"
#include "ResourceSystem/CropsSystem/GGSUCropSeedDataAsset.h"

AGGSUCrop* UGGSUCropsGenerator::SpawnCrop(UGGSUCropSeedDataAsset* CropSeed,  const FVector& Location) const
{
	if (UWorld* World = GetWorld(); World && CropSeed)
	{
		AGGSUCrop* NewCrop = World->SpawnActor<AGGSUCrop>(Location, FRotator(0.f, -90.f, 0.f));
		NewCrop->Initialize(CropSeed);
		return NewCrop;
	}

	return nullptr;
}
