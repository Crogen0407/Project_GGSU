#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ItemSystem/GGSUItemDataAsset.h"

void UGGSUStoreElement::Setup(UGGSUItemDataAsset* TargetItemDataAsset, int Price)
{
	TitleText->SetText(FText::FromName(TargetItemDataAsset->DisplayName));
	if (TargetItemDataAsset->IconTexture)
		IconImage->SetBrushFromTexture(TargetItemDataAsset->IconTexture);

	PriceText->SetText(FText::FromString(FString::FromInt(Price)));
	
	BuyButton->OnClicked.AddDynamic(this, &UGGSUStoreElement::HandleBuyItem);

	CachedTargetItemDataAsset = TargetItemDataAsset;
}

void UGGSUStoreElement::HandleBuyItem()
{
	
}
