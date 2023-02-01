// ShooterOnUnreal Game. All Rights Reserved.

#include "Player/SOUBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASOUBaseCharacter::ASOUBaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent)    ;
}

// Called when the game starts or when spawned
void ASOUBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASOUBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASOUBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASOUBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASOUBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASOUBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ASOUBaseCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASOUBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASOUBaseCharacter::OnStartRunning);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ASOUBaseCharacter::OnStopRunning);
}

void ASOUBaseCharacter::MoveForward(float Amount)
{
    IsMovingForvard = Amount > 0.0f;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASOUBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ASOUBaseCharacter::OnStartRunning() 
{
    WantsToRun = true;
}
void ASOUBaseCharacter::OnStopRunning() 
{
    WantsToRun = false;
}

bool ASOUBaseCharacter::IsRunning() const 
{
    return WantsToRun && IsMovingForvard && !GetVelocity().IsZero();
}