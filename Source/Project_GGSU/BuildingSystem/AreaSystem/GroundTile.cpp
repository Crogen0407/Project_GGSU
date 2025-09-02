// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem/AreaSystem/GroundTile.h"
#include "Engine/Engine.h"

AGroundTile::AGroundTile()
{
	PrimaryActorTick.bCanEverTick = true;
}
void AGroundTile::BeginPlay()
{
	Super::BeginPlay();
}

void AGroundTile::OnClicked()
{
	
}
void AGroundTile::OnHovered()
{
	
}
void AGroundTile::OnUnhovered()
{

}

bool AGroundTile::IsUnlocked() const
{
	return false;
}

void AGroundTile::SetUnlocked(bool bNewState)
{
	// 해금 상태가 변경될 때 시각적 피드백을 추가할 수 있습니다.
	UE_LOG(LogTemp, Warning, TEXT("lock!"));
}