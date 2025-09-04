// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Others/GGSUTitleUI.h"

#include "Core/GGSUGameManager.h"

void UGGSUTitleUI::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (UGGSUGameManager* GameManager = GetGameInstance()->GetSubsystem<UGGSUGameManager>())
	{
		GameManager->GameStartEvent->AddDynamic(this, &UGGSUTitleUI::HandleGameStart);
	}
}

void UGGSUTitleUI::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);
}

void UGGSUTitleUI::HandleGameStart()
{
	// 블루 프린트에서 재정의하는 함수 실행
}
