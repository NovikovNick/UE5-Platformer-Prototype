// Generic Fighting Game

#include "Core/FNGBaseController.h"
#include "Core/FNGGameState.h"

AFNGGameState* AFNGBaseController::GetGameState()
{
  return GetWorld()  //
             ? Cast<AFNGGameState>(GetWorld()->GetGameState())
             : nullptr;
}
