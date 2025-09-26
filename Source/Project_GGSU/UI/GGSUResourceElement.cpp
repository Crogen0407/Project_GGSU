#include "UI/GGSUResourceElement.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ResourceSystem/GGSUResourceManager.h"

void UGGSUResourceElement::NativeConstruct()
{
	Super::NativeConstruct();

	Icon->SetBrushFromTexture(TargetResource->GetIconTexture());
	
	if (UGGSUResourceManager* ResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>())
	{
		if (ResourceManager->ResourceChangedEvents.Find(TargetResource) != nullptr)
		{
			ResourceManager->ResourceChangedEvents[TargetResource].AddDynamic(this, &UGGSUResourceElement::HandleChangeAmountText);
		}
		int Amount = ResourceManager->GetResource(TargetResource);
		AmountText->SetText(FText::AsNumber(Amount));
	}
}

void UGGSUResourceElement::NativeDestruct()
{
	Super::NativeDestruct();

	if (UGGSUResourceManager* ResourceManager = GetGameInstance()->GetSubsystem<UGGSUResourceManager>())
	{
		ResourceManager->ResourceChangedEvents[TargetResource].RemoveDynamic(this, &UGGSUResourceElement::HandleChangeAmountText);
	}
}

void UGGSUResourceElement::HandleChangeAmountText(int CurrentAmount)
{
	AmountText->SetText(FText::AsNumber(CurrentAmount));
}
