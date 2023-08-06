// Generic Fighting Game

#include "Components/FNGPositionComponent.h"
#include "GameFramework/Controller.h"
#include "MetalHeartPlatformerTypes.h"
#include "Core/FNGBaseCharacter.h"

UFNGPositionComponent::UFNGPositionComponent()
{
  PrimaryComponentTick.bCanEverTick = true;
}

void UFNGPositionComponent::UpdateCharacterPosition(AFNGBaseCharacter* FNGPlayer,
                                                    const FPlatformerPlayer& Char)
{
  const auto X = Char.Parameters.Position.X;
  const auto Y = Char.Parameters.Position.Y;
  const auto Width = Char.Parameters.Width;
  const auto Height = Char.Parameters.Height;

  FNGPlayer->MoveTo(X + Width / 2, Y + Height / 2);

  FNGPlayer->SetVelocityX((Char.IsLeftDirection ? -1 : 1) * Char.Parameters.Velocity.X);

  FNGPlayer->SetActorRotation(
      FRotator{0.0f, Char.IsLeftDirection ? 90.0f : -90.0f, 0.0f});

  switch (Char.State)
  {
    case EPlatformerPlayerState::LOW_ATTACK: FNGPlayer->LowAttack(); break;
    case EPlatformerPlayerState::MID_ATTACK: FNGPlayer->MidAttack(); break;
    case EPlatformerPlayerState::OVERHEAD_ATTACK: FNGPlayer->HighAttack(); break;
  }
}
