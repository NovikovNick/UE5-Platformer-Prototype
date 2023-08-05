// Generic Fighting Game


#include "MainMenu/FNGMenuPlayerController.h"

void AFNGMenuPlayerController::BeginPlay() {
  Super::BeginPlay();
  SetInputMode(FInputModeUIOnly{});
  bShowMouseCursor = true;
}
