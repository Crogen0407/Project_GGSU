#include "UI/GGSUUserWidget.h"

void UGGSUUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (IsFade == false) return;
	
	OpacityTimer += InDeltaTime;
	float Percent = FMath::Clamp(OpacityTimer/FadeDuration, 0.f, 1.f);
	SetRenderOpacity(FMath::Lerp(1.f-TargetOpacity, TargetOpacity, Percent));

	if (Percent > 1.f)
	{
		SetRenderOpacity(TargetOpacity);
		IsFade = false;
	}
}

void UGGSUUserWidget::Show(const float Duration)
{
	SetIsEnabled(true);
	TargetOpacity = 1.f;
	OpacityTimer = 0.f;
	FadeDuration = Duration;
	IsFade = true;
}

void UGGSUUserWidget::Hide(const float Duration)
{
	SetIsEnabled(false);
	TargetOpacity = 0.f;
	OpacityTimer = 0.f;
	FadeDuration = Duration;
	IsFade = true;
}
