// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem/AreaSystem/Area.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingSystem/GGSUBuilding.h"

AArea::AArea()
{
	PrimaryActorTick.bCanEverTick = true;

}
void AArea::BeginPlay()
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	ResourceInstance = GameInstance->GetSubsystem<UGGSUResourceInstance>();
	
	Super::BeginPlay();
}

bool AArea::UnlockArea()
{
	if (ResourceInstance->TryRemoveResource(UnlockCurrency, UnlockCost))
	{
		// 이 구역에 속한 모든 땅 해금
		for (AGGSUBuilding* Building : Buildings)
		{
			if (Building)
			{
				Building->OnUnlock();
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("unlock area!"));
		return true;
	}
    
	UE_LOG(LogTemp, Warning, TEXT("not enough money"));
	return false;
}