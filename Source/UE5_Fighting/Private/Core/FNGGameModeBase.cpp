// Generic Fighting Game

#include "Core/FNGGameModeBase.h"
#include "Core/FNGBaseCharacter.h"
#include "Core/FNGPlayerController.h"
#include "Core/FNGEnemyController.h"
#include "Core/FNGGameState.h"
#include "FNGPlatformerFunctionLibrary.h"
#include "MetalHeartPlatformerTypes.h"

FPlatformerGameBuffer Buffer;

AFNGGameModeBase::AFNGGameModeBase()
{
  DefaultPawnClass = AFNGBaseCharacter::StaticClass();
  PlayerControllerClass = AFNGPlayerController::StaticClass();
  GameStateClass = AFNGGameState::StaticClass();

  Buffer.Buffer = new uint8[512];
  Buffer.BufferLength = 0;
}

void AFNGGameModeBase::StartPlay()
{
  Super::StartPlay();

  if (!GetWorld()) return;
  auto World = GetWorld();

  // Spawn platforms
  for (const auto Platform : PlatformData)
  {
    auto Transform =
        FTransform{FRotator::ZeroRotator,
                   FVector{static_cast<float>(Platform.X + Platform.Width / 2),
                           0,
                           static_cast<float>(Platform.Y + Platform.Height / 2)},
                   FVector{static_cast<float>(Platform.Width),  //
                           200,                                 //
                           static_cast<float>(Platform.Height)}};

    auto Spawned = World->SpawnActorDeferred<AFNGBasePlatform>(PlatformClass, Transform);
    if (Spawned)
    {
      Spawned->FinishSpawning(Transform);
    }
  };

  {  // Spawn other players
    FActorSpawnParameters SpawnInfo;
    SpawnInfo.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    RestartPlayer(
        World->SpawnActor<AController>(AFNGEnemyController::StaticClass(), SpawnInfo));
  }

  UFNGPlatformerFunctionLibrary::EvalSetLocation(PlatformData);
  UFNGPlatformerFunctionLibrary::EvalInit();
  UFNGPlatformerFunctionLibrary::EvalStartGame();
}

void AFNGGameModeBase::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
  auto GS = GetGameState<AFNGGameState>();
  if (GS)
  {
    UFNGPlatformerFunctionLibrary::EvalUpdate(GS->Input.bWantsMoveLeft,
                                              GS->Input.bWantsMoveRight,
                                              GS->Input.bWantsJump,
                                              GS->Input.bWantsCrouch,
                                              GS->Input.bWantsAttack,
                                              GS->Input.bWantsBlock);
    GS->PlatformerGameState = UFNGPlatformerFunctionLibrary::EvalGetState(Buffer);
  }
}
