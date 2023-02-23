// ShooterOnUnreal Game. All Rights Reserved.

#include "Components/SOUCharacterMovementComponent.h"
#include "Player/SOUBaseCharacter.h"

float USOUCharacterMovementComponent::GetMaxSpeed() const
{
    const float maxSpeed = Super::GetMaxSpeed();
    const ASOUBaseCharacter* Player = Cast<ASOUBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? maxSpeed * RunModifier : maxSpeed;
}