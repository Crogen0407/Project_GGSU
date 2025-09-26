// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem/GradeSystem/GGSUGradeManager.h"

#include "Utils/GGSUColorPalette.h"

UGGSUGradeManager::UGGSUGradeManager()
{
	static ConstructorHelpers::FObjectFinder<UGGSUColorPalette> GradeColorPalette(TEXT("/Game/DataAssets/DA_GradeColorPalette"));

	if (GradeColorPalette.Object == nullptr) return;
	
	CachedGradeColorPalette = GradeColorPalette.Object;
}

UGGSUGradeManager::~UGGSUGradeManager()
{
}

FColor UGGSUGradeManager::GetGradeColor(EResourceGrade Grade) const
{
	return CachedGradeColorPalette->Colors[static_cast<int>(Grade)];
}