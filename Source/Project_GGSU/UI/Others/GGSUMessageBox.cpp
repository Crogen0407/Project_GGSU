// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Others/GGSUMessageBox.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UGGSUMessageBox::Setup(const FText Text)
{
	ButtonCount = 0;
	FirstButtonClickCallback = nullptr;
	SecondButtonClickCallback = nullptr;
	
	FirstButton->OnClicked.Clear();
	SecondButton->OnClicked.Clear();

	FirstButton->SetVisibility(ESlateVisibility::Collapsed);
	SecondButton->SetVisibility(ESlateVisibility::Collapsed);
	FirstButtonText->SetVisibility(ESlateVisibility::Collapsed);
	SecondButtonText->SetVisibility(ESlateVisibility::Collapsed);
	
	TitleText->SetText(Text);
}

void UGGSUMessageBox::AddButton(const FText Text, const TFunction<void()>& ClickCallback)
{
	if (ButtonCount == 2) return;
	ButtonCount++;

	UButton* TargetButton = ButtonCount == 1 ? FirstButton : SecondButton;
	UTextBlock* TargetButtonText = ButtonCount == 1 ? FirstButtonText : SecondButtonText;

	TargetButtonText->SetText(Text);
	TargetButtonText->SetVisibility(ESlateVisibility::Visible);
	TargetButton->SetVisibility(ESlateVisibility::Visible);

	if (ButtonCount == 1)
	{
		FirstButtonClickCallback = ClickCallback;
		TargetButton->OnClicked.AddDynamic(this, &UGGSUMessageBox::OnFirstButtonClicked);
	}
	else
	{
		SecondButtonClickCallback = ClickCallback;
		TargetButton->OnClicked.AddDynamic(this, &UGGSUMessageBox::OnSecondButtonClicked);
	}
}