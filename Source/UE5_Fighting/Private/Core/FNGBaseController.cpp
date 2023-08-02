// Generic Fighting Game

#include "Core/FNGBaseController.h"
#include "Core/FNGBaseCharacter.h"
#include "Core/FNGGameState.h"
#include "MetalHeartPlatformerTypes.h"
#include "FNGPlatformerFunctionLibrary.h"

void AFNGBaseController::UpdateCharacterPosition(const FPlatformerPlayer& Char)
{
  const auto X = Char.Parameters.Position.X;
  const auto Y = Char.Parameters.Position.Y;
  const auto Width = Char.Parameters.Width;
  const auto Height = Char.Parameters.Height;

  auto FNGPlayer = Cast<AFNGBaseCharacter>(GetPawn());
  FNGPlayer->MoveTo(X + Width / 2, Y + Height / 2);
  FNGPlayer->SetVelocityX((Char.IsLeftDirection ? -1 : 1) * Char.Parameters.Velocity.X);

  FNGPlayer->SetActorRotation(FRotator{0.0f, Char.IsLeftDirection ? 90.0f : -90.0f, 0.0f});

  switch (Char.State)
  {
    case EPlatformerPlayerState::LOW_ATTACK: FNGPlayer->LowAttack(); break;
    case EPlatformerPlayerState::MID_ATTACK: FNGPlayer->MidAttack(); break;
    case EPlatformerPlayerState::OVERHEAD_ATTACK: FNGPlayer->HighAttack(); break;
  }
}

AFNGGameState* AFNGBaseController::GetGameState()
{
  return GetWorld()  //
             ? Cast<AFNGGameState>(GetWorld()->GetGameState())
             : nullptr;
}
