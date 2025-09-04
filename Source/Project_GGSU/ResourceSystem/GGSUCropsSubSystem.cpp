#include "ResourceSystem/GGSUCropsSubSystem.h"
#include "GGSUCrops.h"

AGGSUCrops* UGGSUCropsSubSystem::SpawnCrop(const UGGSUCropsAsset* CropsAsset, const FVector& Location) const
{
	if (UWorld* World = GetWorld(); World && CropsAsset)
	{
		AGGSUCrops* NewCrop = World->SpawnActor<AGGSUCrops>(Location, FRotator::ZeroRotator);
		return NewCrop;
	}

	return nullptr;
}
