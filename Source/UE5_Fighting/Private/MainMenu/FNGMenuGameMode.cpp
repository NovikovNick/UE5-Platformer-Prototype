// Generic Fighting Game

#include "MainMenu/FNGMenuGameMode.h"
#include "MainMenu/FNGMenuHUD.h"
#include "MainMenu/FNGMenuPlayerController.h"

AFNGMenuGameMode::AFNGMenuGameMode()
{
  PlayerControllerClass = AFNGMenuPlayerController::StaticClass();
  HUDClass = AFNGMenuHUD::StaticClass();
}
