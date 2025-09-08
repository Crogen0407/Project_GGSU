#include "ResourceSystem/CropsSystem/GGSUCropsGenerator.h"
#include "GGSUCrop.h"


AGGSUCrop* UGGSUCropsGenerator::SpawnCrop(UGGSUCropDataAsset* CropsDataAsset, const FVector& Location) const
{
	if (UWorld* World = GetWorld(); World && CropsDataAsset)
	{
		AGGSUCrop* NewCrop = World->SpawnActor<AGGSUCrop>(Location, FRotator(0.f, -90.f, 0.f));
		NewCrop->Initialize(CropsDataAsset);
		return NewCrop;
	}

	return nullptr;
}
