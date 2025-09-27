#include "BuildingSystem/GGSUField.h"
#include "ResourceSystem/CropsSystem/GGSUCropsGenerator.h"
#include "ResourceSystem/CropsSystem/GGSUCropsSelection.h"
#include "ResourceSystem/CropsSystem/GGSUCrop.h"

void AGGSUField::OnClicked()
{
	Super::OnClicked();

	// 이미 심어져 있는 작물이 있는지 판별
	if (CurrentCrops != nullptr)
	{
		HarvestCurrentCrops();
		
		return;
	}

	// Crop spawn.
	if (const UGGSUCropsSelection* CropsSelection = GetGameInstance()->GetSubsystem<UGGSUCropsSelection>(); CropsSelection)
		if (UGGSUCropSeedDataAsset* CropSeed = CropsSelection->GetSelectedCropSeed())
			SpawnCrop(CropSeed);
}

void AGGSUField::OnUnlock()
{
	Enable();
	Super::OnUnlock();
}

void AGGSUField::SpawnCrop(UGGSUCropSeedDataAsset* CropSeed)
{
	if (const UGGSUCropsGenerator* CropsGenerator = GetGameInstance()->GetSubsystem<UGGSUCropsGenerator>())
	{
		CurrentCrops = CropsGenerator->SpawnCrop(CropSeed, GetActorLocation());
	}
}

bool AGGSUField::HarvestCurrentCrops()
{
	// TODO : 다 자랐는지 확인
	if (false)
	{
		// TODO : 저장소에 자원 넣는 로직
		// 어쩌구저쩌구

		// 오브젝트 없애기
		if (UWorld* World = GetWorld())
			World->DestroyActor(CurrentCrops);
		
		return true; 
	}


	// TODO : 메시지 띄우기
	return false;		
}
