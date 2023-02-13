// ShooterOnUnreal Game. All Rights Reserved.

#include "Components/SOUHealthComponent.h"
#include "GameFramework/Actor.h"
#include "Dev/SOUFireDamageType.h"
#include "Dev/SOUIceDamageType.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All)

USOUHealthComponent::USOUHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void USOUHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USOUHealthComponent::OnTakeDamage);
    }
}

void USOUHealthComponent::OnTakeDamage(
    AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    Health -= Damage;
    UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Damage);

    if (DamageType)
    {
        if (DamageType->IsA<USOUFireDamageType>())
        {
            UE_LOG(LogHealthComponent, Display, TEXT("So hooooooooooooot!!!!!"));
        }
        else if (DamageType->IsA<USOUIceDamageType>())
        {
            UE_LOG(LogHealthComponent, Display, TEXT("So cooooooold!!!!!"   ));
        }
    }
}
