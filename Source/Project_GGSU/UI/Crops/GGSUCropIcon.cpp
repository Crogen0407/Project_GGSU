#include "UI/Crops/GGSUCropIcon.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "ResourceSystem/CropsSystem/GGSUCropDataAsset.h"
#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"

void UGGSUCropIcon::SetTargetCrop(UGGSUCropDataAsset* InCrop)
{
	TargetCrop = InCrop;

	if (TargetCrop)
		Button->OnClicked.AddDynamic(this, &UGGSUCropIcon::HandleSelectTargetCrop);
	
	// TODO : 아이콘 만들어야 됨
	//IconImage->SetBrush(InCrop->Icon);
}

void UGGSUCropIcon::HandleSelectTargetCrop()
{
	if (UGGSUCropsSelection* CropsSelection = GetGameInstance()->GetSubsystem<UGGSUCropsSelection>())
	{
		CropsSelection->SetSelectedCrop(TargetCrop);
	}
}


