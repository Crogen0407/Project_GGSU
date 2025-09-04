// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem/GGSUField.h"

#include "ResourceSystem/CropsSystem/GGSUCropDataAsset.h"
#include "ResourceSystem/CropsSystem/GGSUCropsGenerator.h"
#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"

void AGGSUField::OnClicked()
{
	Super::OnClicked();

	// 이미 심어져 있는 작물이 있는지 판별
	if (CurrentCrops.Num() > 0)
	{
		// 심어져 있다면 수확 시도
		HarvestCurrentCrops(); 
			
		// TODO : 메세지 UI 띄우는 로직
		return;
	}

	// Crop spawn.
	if (const UGGSUCropsSelection* CropsSelection = GetGameInstance()->GetSubsystem<UGGSUCropsSelection>(); CropsSelection)
		if (UGGSUCropDataAsset* CropDataAsset = CropsSelection->GetSelectedCrop())
			SpawnCrop(CropDataAsset);
}

void AGGSUField::SpawnCrop(UGGSUCropDataAsset* CropDataAsset)
{
	if (const UGGSUCropsGenerator* CropsGenerator = GetGameInstance()->GetSubsystem<UGGSUCropsGenerator>())
	{
		for (int i = 0; i < CropSpawnLocations.Max(); ++i)
		{
			CurrentCrops.Add(CropsGenerator->SpawnCrop(CropDataAsset, CropSpawnLocations[i]->GetComponentLocation()));
		}	
	}
}

void AGGSUField::HarvestCurrentCrops()
{
	// 다 자랐다면 수확
}
