// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem/AreaSystem/Area.h"

AArea::AArea()
{
	PrimaryActorTick.bCanEverTick = true;

}
void AArea::BeginPlay()
{
	Super::BeginPlay();
}

bool AArea::UnlockArea()
{
	if (true) // 플레이어 돈이 구매 비용보다 많거나 같은지 확인
	{
		// 비용 지불 로직

		// 이 구역에 속한 모든 땅 해금
		for (AGroundTile* Tile : GroundTiles)
		{
			if (Tile)
			{
				Tile->SetUnlocked(true);
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("unlock area!"));
		return true;
	}
    
	UE_LOG(LogTemp, Warning, TEXT("not enough money"));
	return false;
}