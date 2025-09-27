#include "UI/PopupUI/Stores/GGSUStoreBuyMessageBox.h"
#include "ResourceSystem/GGSUResourceManager.h"

void UGGSUStoreBuyMessageBox::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UGGSUStoreBuyMessageBox::Setup(const FText Text)
{
	Super::Setup(Text);

	AddButton(FText::FromString("취소"), [this]
	{
		Hide(0.25f);
	});
	
	AddButton(FText::FromString("구매"), [this]
	{
		if (UGGSUResourceManager* ResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>())
		{
			ResourceManager->RemoveResource(GoldResource, ItemCount * ItemPrice);
			ResourceManager->AddResource(TargetResource, ItemCount);
		}
	});
}
