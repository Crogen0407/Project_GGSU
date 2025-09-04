#include "ResourceSystem/CropsSystem/GGSUCropsGenerator.h"
#include "GGSUCrops.h"


AGGSUCrops* UGGSUCropsGenerator::SpawnCrop(UGGSUCropDataAsset* CropsDataAsset, const FVector& Location) const
{
	if (UWorld* World = GetWorld(); World && CropsDataAsset)
	{
		AGGSUCrops* NewCrop = World->SpawnActor<AGGSUCrops>(Location, FRotator::ZeroRotator);
		NewCrop->Initialize(CropsDataAsset);
		return NewCrop;
	}

	return nullptr;
}
