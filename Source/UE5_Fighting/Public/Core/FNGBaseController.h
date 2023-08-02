// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FNGBaseController.generated.h"

class AFNGGameState;
struct FPlatformerPlayer;

UCLASS()
class UE5_FIGHTING_API AFNGBaseController : public APlayerController
{
  GENERATED_BODY()

protected:
  void UpdateCharacterPosition(const FPlatformerPlayer& Character);

  AFNGGameState* GetGameState();
};
