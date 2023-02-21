// ShooterOnUnreal Game. All Rights Reserved.

#include "SOUGameModeBase.h"
#include "Player/SOUBaseCharacter.h"
#include "Player/SOUPlayerController.h"
#include "UI/SOUGameHUD.h"

ASOUGameModeBase::ASOUGameModeBase()
{
    DefaultPawnClass = ASOUBaseCharacter::StaticClass();
    PlayerControllerClass = ASOUPlayerController::StaticClass();
    HUDClass = ASOUGameHUD::StaticClass();
}