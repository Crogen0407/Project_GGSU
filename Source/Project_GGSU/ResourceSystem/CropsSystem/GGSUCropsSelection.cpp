#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"

void UGGSUCropsSelection::SetSelectedCropSeed(UGGSUCropSeedDataAsset* NewCropSeed)
{
	SelectedCropSeed = NewCropSeed;
}

UGGSUCropSeedDataAsset* UGGSUCropsSelection::GetSelectedCropSeed() const
{
	return SelectedCropSeed;
}
