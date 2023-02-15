// ShooterOnUnreal Game. All Rights Reserved.

#include "Components/SOUHealthComponent.h"
#include "GameFramework/Actor.h"

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
    OnHealthChanged.Broadcast(Health);

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USOUHealthComponent::OnTakeDamage);
    }
}

void USOUHealthComponent::OnTakeDamage(
    AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead())
        return;
    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(Health);
    if (IsDead())
    {
        OnDeath.Broadcast();
    }
}
