// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGSUCropSelectBar.generated.h"

class UGGSUCropsSetDataAsset;
class UGGSUCropIcon;
class UHorizontalBox;

UCLASS()
class PROJECT_GGSU_API UGGSUCropSelectBar : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	void CreateCropElements();

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> CropIcons;
	
	// 에디터에서 생성할 자식 위젯의 WBP 클래스를 지정할 수 있습니다.
	UPROPERTY(EditDefaultsOnly, Category = "Crop")
	TSubclassOf<UGGSUCropIcon> ItemWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Crop")
	UGGSUCropsSetDataAsset* CropSetDataAsset;
};
