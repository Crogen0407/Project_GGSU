#include "UI/Crops/GGSUCropSelectBar.h"
#include "UI/Crops/GGSUCropIcon.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "ResourceSystem/GGSUResourceSetDataAsset.h"

void UGGSUCropSelectBar::NativeConstruct()
{
	UE_LOG(LogTemp, Log, TEXT("NativeConstruct"));
	
	Super::NativeConstruct();

	CreateCropElements();
}

void UGGSUCropSelectBar::CreateCropElements()
{
	if (CropIcons && ItemWidgetClass)
	{
		for (int32 i = 0; i < CropSetDataAsset->GetCropsCount(); ++i)
		{
			if (UGGSUCropIcon* CreatedItemWidget = CreateWidget<UGGSUCropIcon>(this, ItemWidgetClass))
			{
				if (UHorizontalBoxSlot* NewSlot = CropIcons->AddChildToHorizontalBox(CreatedItemWidget))
				{
					FSlateChildSize ChildSize;
					ChildSize.SizeRule = ESlateSizeRule::Fill;
					ChildSize.Value = 1.0f;
					
					NewSlot->SetSize(ChildSize);
					NewSlot->SetVerticalAlignment(VAlign_Center);
					NewSlot->SetHorizontalAlignment(HAlign_Center);
					NewSlot->SetPadding(FMargin(5.f));
				}
				
				// 초기화
				CreatedItemWidget->SetTargetCropSeed(CropSetDataAsset->GetCropSeedAssets()[i]);
			}
		}
	}
}
