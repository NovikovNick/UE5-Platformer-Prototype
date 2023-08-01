// Generic Fighting Game

#include "Core/FNGGameModeBase.h"
#include "Core/FNGBaseCharacter.h"
#include "Core/FNGPlayerController.h"
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

  UFNGPlatformerFunctionLibrary::EvalSetLocation(PlatformData);
  UFNGPlatformerFunctionLibrary::EvalInit();
  UFNGPlatformerFunctionLibrary::EvalStartGame();
}

void AFNGGameModeBase::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
  const auto GS = GetGameState<AFNGGameState>();
  if (GS)
  {
    GS->PlatformerGameState = UFNGPlatformerFunctionLibrary::EvalGetState(Buffer);
    const auto Pos_X = GS->PlatformerGameState.Player.Parameters.Position.X;
    const auto Pos_Y = GS->PlatformerGameState.Player.Parameters.Position.Y;

    const auto Vel_X = GS->PlatformerGameState.Player.Parameters.Velocity.X;
    const auto Vel_Y = GS->PlatformerGameState.Player.Parameters.Velocity.Y;
    /*UE_LOG(LogTemp,
           Warning,
           TEXT("Position [%5.0f,%5.0f], Velocity [%5.0f,%5.0f]"),
           Pos_X,
           Pos_Y,
           Vel_X,
           Vel_Y);*/
  }
}
