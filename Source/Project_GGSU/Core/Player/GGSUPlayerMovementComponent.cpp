// Fill out your copyright notice in the Description page of Project Settings.


#include "GGSUPlayerMovementComponent.h"
#include "GGSUPlayerPawn.h"

void UGGSUPlayerMovementComponent::MoveRight(float Val)
{
	if (PlayerPawnOwner == nullptr)
		PlayerPawnOwner = GetOwner<AGGSUPlayerPawn>();

	if (Val != 0.f)
	{
		if (auto Controller = PlayerPawnOwner->Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			AddMovementInput( FRotationMatrix(ControlSpaceRot).GetScaledAxis( EAxis::Y ), Val );
		}
	}
}

void UGGSUPlayerMovementComponent::MoveForward(float Val)
{
	if (PlayerPawnOwner == nullptr)
		PlayerPawnOwner = GetOwner<AGGSUPlayerPawn>();
	
	if (Val != 0.f)
	{
		if (auto Controller = PlayerPawnOwner->Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			AddMovementInput( FRotationMatrix(ControlSpaceRot).GetScaledAxis( EAxis::X ), Val );
		}
	}
}

void UGGSUPlayerMovementComponent::AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
{
	AddInputVector(WorldDirection * ScaleValue, bForce);
}
