#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ItemSystem/GGSUItemDataAsset.h"
#include "UI/GGSUUIManager.h"
#include "UI/PopupUI/Stores/GGSUStoreBuyMessageBox.h"

void UGGSUStoreElement::Setup(UGGSUItemDataAsset* TargetItemDataAsset, int Price)
{
	TitleText->SetText(FText::FromName(TargetItemDataAsset->Name));
	if (TargetItemDataAsset->IconTexture)
		IconImage->SetBrushFromTexture(TargetItemDataAsset->IconTexture);

	PriceText->SetText(FText::FromString(FString::FromInt(Price)));
	
	BuyButton->OnClicked.AddDynamic(this, &UGGSUStoreElement::HandleBuyItem);

	CachedTargetItemDataAsset = TargetItemDataAsset;
	CachedPrice = Price;
}

void UGGSUStoreElement::HandleBuyItem()
{
	if (UGGSUUIManager* UIManager = GetGameInstance()->GetSubsystem<UGGSUUIManager>())
	{
		if (UGGSUStoreBuyMessageBox* MessageBox = Cast<UGGSUStoreBuyMessageBox>(UIManager->ShowPopupUI(StoreBuyMessageBoxClass)))
		{
			MessageBox->TargetItem = CachedTargetItemDataAsset;
			MessageBox->ItemPrice = CachedPrice;

			const FString Text = CachedTargetItemDataAsset->Name.ToString() + "을(를) 구매하시겠습니까?"; 
			MessageBox->Setup(FText::FromString(Text));
		}
	}
}
