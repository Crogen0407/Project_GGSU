#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"

void UGGSUCropsSelection::SetSelectedCrop(UGGSUCropDataAsset* NewCropDataAsset)
{
	SelectedCropDataAsset = NewCropDataAsset;
}

UGGSUCropDataAsset* UGGSUCropsSelection::GetSelectedCrop() const
{
	return SelectedCropDataAsset;
}
