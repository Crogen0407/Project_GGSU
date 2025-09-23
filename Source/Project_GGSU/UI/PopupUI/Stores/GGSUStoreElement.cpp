#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ItemSystem/GGSUItemDataAsset.h"

void UGGSUStoreElement::Setup(UGGSUItemDataAsset* TargetItemDataAsset)
{
	TitleText->SetText(FText::FromName(TargetItemDataAsset->DisplayName));
	BuyButton->OnClicked.AddDynamic(this, &UGGSUStoreElement::HandleBuyItem);
	CachedTargetItemDataAsset = TargetItemDataAsset;
}

void UGGSUStoreElement::HandleBuyItem()
{
	
}
