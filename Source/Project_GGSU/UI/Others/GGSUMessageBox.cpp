// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Others/GGSUMessageBox.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UGGSUMessageBox::Init(const FText& Text)
{
	ButtonCount = 0;
	FirstButtonClickCallback = nullptr;
	SecondButtonClickCallback = nullptr;
	FirstButton->OnClicked.Clear();
	FirstButton->SetVisibility(ESlateVisibility::Collapsed);
	SecondButton->OnClicked.Clear();
	SecondButton->SetVisibility(ESlateVisibility::Collapsed);
	
	TitleText->SetText(Text);
}

void UGGSUMessageBox::AddButton(const FText& Text, const TFunction<void()>& ClickCallback)
{
	if (ButtonCount == 2) return;
	ButtonCount++;

	UButton* TargetButton = ButtonCount == 1 ? FirstButton : SecondButton;
	UTextBlock* TargetButtonText = ButtonCount == 1 ? FirstButtonText : SecondButtonText;
	if (ButtonCount == 1)
		FirstButtonClickCallback = ClickCallback;
	else
		SecondButtonClickCallback = ClickCallback;
	TargetButtonText->SetText(Text);
	TargetButton->SetVisibility(ESlateVisibility::Visible);
	TargetButton->OnClicked.AddDynamic(this, &UGGSUMessageBox::OnFirstButtonClicked);
}