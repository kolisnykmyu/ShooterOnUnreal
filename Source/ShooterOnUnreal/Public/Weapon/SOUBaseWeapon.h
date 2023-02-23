// ShooterOnUnreal Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SOUBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SHOOTERONUNREAL_API ASOUBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ASOUBaseWeapon();

    virtual void Fire();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    virtual void BeginPlay() override;
};
