// Generic Fighting Game

#include "Core/FNGEnemyController.h"
#include "Core/FNGGameState.h"
#include "MetalHeartPlatformerTypes.h"

void AFNGEnemyController::Tick(float DeltaSeconds)
{
  if (GetGameState()) UpdateCharacterPosition(GetGameState()->PlatformerGameState.Enemy);
}
