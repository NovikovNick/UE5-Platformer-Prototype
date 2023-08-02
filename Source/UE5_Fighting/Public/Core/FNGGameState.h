// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MetalHeartPlatformerTypes.h"
#include "FNGGameState.generated.h"

/**
 *
 */
UCLASS()
class UE5_FIGHTING_API AFNGGameState : public AGameStateBase
{
  GENERATED_BODY()

public:
  FInputData Input;
  FPlatformerGameState PlatformerGameState;

  uint8_t game_state_buf[512];
  int length = 0;
};
