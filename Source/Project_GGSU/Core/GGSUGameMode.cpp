// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUGameMode.h"
#include "GameFramework\HUD.h"

AGGSUGameMode::AGGSUGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Core/Player/BP_GGSUPlayerPawn"));
	if (PlayerPawnBPClass.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AController> PlayerControllerBPClass(TEXT("/Game/Blueprints/Core/Player/BP_GGSUPlayerController"));
	if (PlayerControllerBPClass.Succeeded())
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AHUD> HUDControllerBPClass(TEXT("/Game/Widget/HUD/BP_GameHUD"));
	if (HUDControllerBPClass.Succeeded())
	{
		HUDClass = HUDControllerBPClass.Class; 		
	}
}
