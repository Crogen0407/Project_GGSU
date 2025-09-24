#include "UI/PopupUI/Stores/GGSUStorePopup.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "StoreSystem/GGSUStoreProductsDataAsset.h"
#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "UI/PopupUI/Stores/GGSUStoreCategoryButton.h"
#include "UI/PopupUI/Stores/GGSUStoreCategory.h"
#include "Components/HorizontalBoxSlot.h"
#include "ResourceSystem/GGSUResourceDataAsset.h"

void UGGSUStorePopup::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CachedCategoryIndex = 0;
	
	for (auto ProductsGroup : StoreProductsDataAsset->Showcases)
	{
		if (auto NewStoreCategoryButton = CreateWidget<UGGSUStoreCategoryButton>(this, StoreCategoryButtonClass))
		{
			int index = CachedCategoryIndex;
			NewStoreCategoryButton->CategoryNameText->SetText(FText::FromString(ProductsGroup.Key));
			NewStoreCategoryButton->OnClicked.BindLambda([this, index]()
			{
				StoreCategorySwitcher->SetActiveWidgetIndex(index);
			});
			NewStoreCategoryButton->Setup();
			UHorizontalBoxSlot* ButtonSlot = StoreCategoryButtons->AddChildToHorizontalBox(NewStoreCategoryButton);
			ButtonSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
			NewStoreCategoryButton->SetPadding(FMargin(10.0f, 25.0f, 10.0f, 0.0f));
		}

		if (auto NewStoreCategory = CreateWidget<UGGSUStoreCategory>(this, StoreCategoryClass))
		{
			StoreCategorySwitcher->AddChild(NewStoreCategory);
			NewStoreCategory->SetPadding(FMargin(10.0f));

			for (auto Item : ProductsGroup.Value.Items)
			{
				if (auto NewStoreElement = CreateWidget<UGGSUStoreElement>(this, StoreElementClass))
				{
					UE_LOG(LogTemp, Log, TEXT("Character Name :: %s"), *Item.Key->Name.ToString());
					NewStoreElement->Setup(Item.Key, Item.Value);
					NewStoreCategory->StoreElementList->AddChild(NewStoreElement);
					NewStoreElement->SetPadding(FMargin(50.0f));
				}
			}
		}

		CachedCategoryIndex++; 
	}
}
