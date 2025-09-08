#include "UI/GGSUUIManager.h"
#include "UI/GGSUUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

UGGSUUserWidget* UGGSUUIManager::ShowPopupUI(TSubclassOf<UGGSUUserWidget> UserWidgetClass)
{
	if (false == WidgetInstances.Contains(UserWidgetClass))
	{
		UGGSUUserWidget* UserWidgetInstance = CreateWidget<UGGSUUserWidget>(GetWorld()->GetFirstPlayerController(), UserWidgetClass);
		WidgetInstances.Add(UserWidgetClass, UserWidgetInstance);

		UserWidgetInstance->AddToViewport();
						
		return UserWidgetInstance;
	}

	if (ESlateVisibility::HitTestInvisible == WidgetInstances[UserWidgetClass]->GetVisibility())
		WidgetInstances[UserWidgetClass]->Show(0.25f);
	
	return WidgetInstances[UserWidgetClass];
}

void UGGSUUIManager::HidePopupUI(TSubclassOf<UGGSUUserWidget> UserWidgetClass)
{
	if (false == WidgetInstances.Contains(UserWidgetClass)) return;

	if (ESlateVisibility::Visible == WidgetInstances[UserWidgetClass]->GetVisibility())
		WidgetInstances[UserWidgetClass]->Hide(0.25f);
}
