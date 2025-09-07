#include "UI/Crops/GGSUCropSelectBar.h"
#include "UI/Crops/GGSUCropIcon.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "ResourceSystem/CropsSystem/GGSUCropsSetDataAsset.h"

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
		for (int32 i = 0; i < CropSetDataAsset->GetDropsCount(); ++i)
		{
			UGGSUCropIcon* CreatedItemWidget = CreateWidget<UGGSUCropIcon>(this, ItemWidgetClass);

			if (CreatedItemWidget)
			{
				UHorizontalBoxSlot* NewSlot = CropIcons->AddChildToHorizontalBox(CreatedItemWidget);

				if (NewSlot)
				{
					FSlateChildSize ChildSize;
					ChildSize.SizeRule = ESlateSizeRule::Fill;
					ChildSize.Value = 1.0f;
					
					NewSlot->SetSize(ChildSize);
					NewSlot->SetVerticalAlignment(VAlign_Center);
					NewSlot->SetHorizontalAlignment(HAlign_Center);
					NewSlot->SetPadding(FMargin(10.f));
				}
				
				// 초기화
				CreatedItemWidget->SetTargetCrop(CropSetDataAsset->GetCropAssets()[i]);
			}
		}
	}
}
