// ShooterOnUnreal Game. All Rights Reserved.

#include "Weapon/SOUBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

ASOUBaseWeapon::ASOUBaseWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);
}

void ASOUBaseWeapon::BeginPlay()
{
    Super::BeginPlay();
}
