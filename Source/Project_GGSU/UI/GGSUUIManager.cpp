#include "UI/GGSUUIManager.h"
#include "UI/GGSUUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Core/Player/GGSUPlayerController.h"
#include "GameFramework/PlayerController.h"

UGGSUUserWidget* UGGSUUIManager::ShowPopupUI(const TSubclassOf<UGGSUUserWidget> UserWidgetClass)
{
	if (false == WidgetInstances.Contains(UserWidgetClass))
	{
		UGGSUUserWidget* UserWidgetInstance = CreateWidget<UGGSUUserWidget>(GetWorld()->GetFirstPlayerController(), UserWidgetClass);
		WidgetInstances.Add(UserWidgetClass, UserWidgetInstance);

		UserWidgetInstance->SetRenderOpacity(0.f);
		UserWidgetInstance->SetVisibility(ESlateVisibility::HitTestInvisible);
		UserWidgetInstance->AddToViewport();
	}

	if (ESlateVisibility::HitTestInvisible == WidgetInstances[UserWidgetClass]->GetVisibility())
		WidgetInstances[UserWidgetClass]->Show(0.25f);

	if (AGGSUPlayerController* PC = Cast<AGGSUPlayerController>(GetWorld()->GetFirstPlayerController()))
		PC->Disable();
	
	return WidgetInstances[UserWidgetClass];
}

void UGGSUUIManager::HidePopupUI(TSubclassOf<UGGSUUserWidget> UserWidgetClass)
{
	if (false == WidgetInstances.Contains(UserWidgetClass)) return;

	if (ESlateVisibility::Visible == WidgetInstances[UserWidgetClass]->GetVisibility())
		WidgetInstances[UserWidgetClass]->Hide(0.25f);

	if (AGGSUPlayerController* PC = Cast<AGGSUPlayerController>(GetWorld()->GetFirstPlayerController()))
		PC->Enable();
}
