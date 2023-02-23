// ShooterOnUnreal Game. All Rights Reserved.

#include "Components/SOUWeaponComponent.h"
#include "Weapon/SOUBaseWeapon.h"
#include "GameFramework/Character.h"

USOUWeaponComponent::USOUWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USOUWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapon();
}

void USOUWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    CurrentWeapon = GetWorld()->SpawnActor<ASOUBaseWeapon>(WeaponClass);
    if (!CurrentWeapon) return;

    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
}

void USOUWeaponComponent::Fire()
{
    if (!CurrentWeapon) return;
    CurrentWeapon->Fire();
}