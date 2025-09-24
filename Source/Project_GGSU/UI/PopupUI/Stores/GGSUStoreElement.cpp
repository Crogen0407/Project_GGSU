#include "UI/PopupUI/Stores/GGSUStoreElement.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ItemSystem/GGSUItemDataAsset.h"
#include "UI/GGSUUIManager.h"
#include "UI/PopupUI/Stores/GGSUStoreBuyMessageBox.h"

void UGGSUStoreElement::Setup(UGGSUResourceDataAsset* TargetResourceDataAsset, const int Price)
{
	TitleText->SetText(FText::FromName(TargetResourceDataAsset->Name));
	if (TargetResourceDataAsset->IconTexture)
		IconImage->SetBrushFromTexture(TargetResourceDataAsset->IconTexture);

	PriceText->SetText(FText::FromString(FString::FromInt(Price)));
	
	BuyButton->OnClicked.AddDynamic(this, &UGGSUStoreElement::HandleBuyItem);

	CachedTargetItemDataAsset = TargetResourceDataAsset;
	CachedPrice = Price;
}

void UGGSUStoreElement::HandleBuyItem()
{
	if (UGGSUUIManager* UIManager = GetGameInstance()->GetSubsystem<UGGSUUIManager>())
	{
		if (UGGSUStoreBuyMessageBox* MessageBox = Cast<UGGSUStoreBuyMessageBox>(UIManager->ShowPopupUI(StoreBuyMessageBoxClass)))
		{
			MessageBox->TargetResource = CachedTargetItemDataAsset;
			MessageBox->ItemPrice = CachedPrice;

			const FString Text = CachedTargetItemDataAsset->Name.ToString() + "을(를) 구매하시겠습니까?"; 
			MessageBox->Setup(FText::FromString(Text));
		}
	}
}
