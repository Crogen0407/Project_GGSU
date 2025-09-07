#include "UI/GGSUUIManager.h"
#include "UI/GGSUUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

UGGSUUserWidget* UGGSUUIManager::ShowPopupUI(TSubclassOf<UGGSUUserWidget> UserWidgetClass)
{
	if (WidgetInstances.Contains(UserWidgetClass) == false)
	{
		UGGSUUserWidget* UserWidgetInstance = CreateWidget<UGGSUUserWidget>(GetWorld()->GetFirstPlayerController(), UserWidgetClass);
		WidgetInstances.Add(UserWidgetClass, UserWidgetInstance);

		return UserWidgetInstance;
	}

	return WidgetInstances[UserWidgetClass];
}
