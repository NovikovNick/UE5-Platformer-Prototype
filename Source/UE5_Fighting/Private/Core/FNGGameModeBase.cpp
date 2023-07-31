// Generic Fighting Game

#include "Core/FNGGameModeBase.h"
#include "Core/FNGBaseCharacter.h"
#include "Core/FNGPlayerController.h"
#include "Core/FNGGameState.h"
#include "FNGPlatformerFunctionLibrary.h"

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
  auto Transform = FTransform{FRotator::ZeroRotator, FVector::Zero()};
  auto Spawned = World->SpawnActorDeferred<AFNGBasePlatform>(PlatformClass, Transform);

  if (Spawned)
  {
    Spawned->FinishSpawning(Transform);
  }
  /*
  {2, 0, 32, 256, {0, 640}}
  {3, 0, 32, 256, {1864, 640}}
  */
  /*PlatformData.Add({0, 0, 1864, 32, {0, 608}});
  PlatformData.Add({1, 0, 224, 32, {672, 736}});
  auto Platform = PlatformData.GetData();*/

  UFNGPlatformerFunctionLibrary::EvalSetLocation();
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
