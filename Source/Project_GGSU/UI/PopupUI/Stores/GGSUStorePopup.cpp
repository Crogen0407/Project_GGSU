#include "UI/PopupUI/Stores/GGSUStorePopup.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/WidgetSwitcher.h"
#include "StoreSystem/GGSUStoreProductsDataAsset.h"
#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "UI/PopupUI/Stores/GGSUStoreCategoryButton.h"
#include "UI/PopupUI/Stores/GGSUStoreCategory.h"

void UGGSUStorePopup::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CachedCategoryIndex = 0;
	
	for (auto ProductsGroup : StoreProductsDataAsset->Showcases)
	{
		if (auto NewStoreCategoryButton = CreateWidget<UGGSUStoreCategoryButton>(this, StoreCategoryButtonClass))
		{
			NewStoreCategoryButton->Button->OnClicked.AddDynamic(this, &UGGSUStorePopup::HandleOpenCategory);
			StoreCategoryButtons->AddChildToHorizontalBox(NewStoreCategoryButton);
			NewStoreCategoryButton->SetPadding(FMargin(10.0f, 25.0f, 10.0f, 0.0f));
		}
		
		for (auto Item : ProductsGroup.Value.Items)
		{
			if (auto NewStoreCategory = CreateWidget<UGGSUStoreCategory>(this, StoreCategoryClass))
			{
				StoreCategorySwitcher->AddChild(NewStoreCategory);
				NewStoreCategory->SetPadding(FMargin(10.0f));
				
				if (auto NewStoreElement = CreateWidget<UGGSUStoreElement>(this, StoreElementClass))
				{
					NewStoreElement->Setup(Item.Key, Item.Value);
					NewStoreCategory->StoreElementList->AddChild(NewStoreElement);
					NewStoreElement->SetPadding(FMargin(50.0f));
				}
			}
		}
		CachedCategoryIndex++; 
	}
}

void UGGSUStorePopup::HandleOpenCategory()
{
	int Index = CachedCategoryIndex;
	UE_LOG(LogTemp, Log, TEXT("%d"), Index);
	StoreCategorySwitcher->SetActiveWidgetIndex(Index);
}
