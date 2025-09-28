// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUCropDataAsset.h"

int UGGSUCropDataAsset::GetSellingPrice()
{
	const FDateTime Time = UGGSUDateManager::GetTime();
		
	const int32 Day = Time.GetDay();
	const int32 Month = Time.GetMonth();
	const int32 Year = Time.GetYear();
	const int32 RandomSeed = Day + Month + Year + GetTypeHash(Name)+ 98274092;
		
	const int RandomRange = GenerateAndPrintRandomNumbers(RandomSeed);
		
	return (static_cast<int>(CropGrade) + 1) * SellingPrice + RandomRange;
}

int UGGSUCropDataAsset::GenerateAndPrintRandomNumbers(const int Seed)
{
	RandomStream.Initialize(Seed);
	const int32 RandomInt = RandomStream.RandRange(-5, 5);

	return RandomInt;
}
