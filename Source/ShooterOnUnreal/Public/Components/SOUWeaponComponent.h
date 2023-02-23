// ShooterOnUnreal Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SOUWeaponComponent.generated.h"

class ASOUBaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTERONUNREAL_API USOUWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USOUWeaponComponent();

    void Fire();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ASOUBaseWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponSocket";

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    ASOUBaseWeapon* CurrentWeapon = nullptr;

    void SpawnWeapon();
};
