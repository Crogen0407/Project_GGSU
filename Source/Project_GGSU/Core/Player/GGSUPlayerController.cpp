// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUPlayerController.h"

AGGSUPlayerController::AGGSUPlayerController()
{
	// 커서 표시
	bShowMouseCursor = true;

	// 커서 모양 변경
	static ConstructorHelpers::FObjectFinder<UTexture2D> CursorTexture(TEXT("/Game/UI/MyCursor.MyCursor"));
	if (CursorTexture.Succeeded())
	{
		CurrentMouseCursor = EMouseCursor::Custom;
	}
}

FRotator AGGSUPlayerController::GetControlRotation() const
{
	return FRotator(0, -45.f, 0);
}
