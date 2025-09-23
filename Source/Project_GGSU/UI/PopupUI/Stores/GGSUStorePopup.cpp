#include "UI/PopupUI/Stores/GGSUStorePopup.h"
#include "Components/HorizontalBox.h"
#include "ItemSystem/GGSUItemDataAsset.h"
#include "StoreSystem/GGSUStoreProductsDataAsset.h"
#include "UI/PopupUI/Stores/GGSUStoreElement.h"

void UGGSUStorePopup::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	for (auto ProductsGroup : StoreProductsDataAsset->Showcases)
	{
		for (auto Item : ProductsGroup.Value.Items)
		{
			if (auto NewStoreElement = CreateWidget<UGGSUStoreElement>(this, StoreElementClass))
			{
				NewStoreElement->Setup(Item);
				StoreElements.Add(Item, NewStoreElement);
				StoreElementList->AddChild(NewStoreElement);
				NewStoreElement->SetPadding(FMargin(50.0f));
				UE_LOG(LogTemp, Log, TEXT("asfasdf"));
			}
		}
	}
}
