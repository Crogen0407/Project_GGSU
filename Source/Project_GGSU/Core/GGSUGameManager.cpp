// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GGSUGameManager.h"

void UGGSUGameManager::GameStart()
{
	GameStartEvent->Broadcast();
}
