#include "UI/GGSUUserWidget.h"

void UGGSUUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (IsFade == false) return;
	
	OpacityTimer += InDeltaTime;
	const float Percent = OpacityTimer/FadeDuration;
	SetRenderOpacity(FMath::Lerp(1.f-TargetOpacity, TargetOpacity, Percent));

	if (Percent > 1.f)
	{
		SetRenderOpacity(TargetOpacity);
		IsFade = false;
		SetIsEnabled(TargetOpacity == 1.f);
	}
}

void UGGSUUserWidget::Show(const float Duration)
{
	TargetOpacity = 1.f;
	OpacityTimer = 0.f;
	FadeDuration = Duration;
	IsFade = true;
}

void UGGSUUserWidget::Hide(const float Duration)
{
	TargetOpacity = 0.f;
	OpacityTimer = 0.f;
	FadeDuration = Duration;
	IsFade = true;
}
