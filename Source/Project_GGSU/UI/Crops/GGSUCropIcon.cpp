#include "UI/Crops/GGSUCropIcon.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "ResourceSystem/CropsSystem/GGSUCropSeedDataAsset.h"
#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"

void UGGSUCropIcon::SetTargetCropSeed(UGGSUCropSeedDataAsset* InCropSeed)
{
	TargetCrop = InCropSeed;

	if (TargetCrop)
		Button->OnClicked.AddDynamic(this, &UGGSUCropIcon::HandleSelectTargetCrop);
	
	if (InCropSeed->GetIconTexture())
		IconImage->SetBrushFromTexture(InCropSeed->GetIconTexture());
}

void UGGSUCropIcon::HandleSelectTargetCrop()
{
	if (UGGSUCropsSelection* CropsSelection = GetGameInstance()->GetSubsystem<UGGSUCropsSelection>())
	{
		CropsSelection->SetSelectedCropSeed(TargetCrop);
	}
}


