// Generic Fighting Game

#include "Core/FNGBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Core/FNGGameState.h"

AFNGBaseCharacter::AFNGBaseCharacter()
{
  PrimaryActorTick.bCanEverTick = true;

  SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
  SpringArmComp->bUsePawnControlRotation = true;
  SpringArmComp->SocketOffset = FVector{0.0, 100.0, 60.0};
  SpringArmComp->SetupAttachment(GetRootComponent());

  CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
  CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AFNGBaseCharacter::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void AFNGBaseCharacter::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

  const auto GS = GetWorld()  //
                      ? Cast<AFNGGameState>(GetWorld()->GetGameState())
                      : nullptr;

  if (GS)
  {
    const auto X = GS->PlatformerGameState.Player.Parameters.Position.X;
    const auto Y = GS->PlatformerGameState.Player.Parameters.Position.Y;
    const auto Width = GS->PlatformerGameState.Player.Parameters.Width;
    const auto Height = GS->PlatformerGameState.Player.Parameters.Height;

    FVector Position{X + Width / 2, 0.0, Y + Height / 2};
    SetActorLocation(Position);

    VelocityX = GS->PlatformerGameState.Player.Parameters.Velocity.X;

    switch (GS->PlatformerGameState.Player.State)
    {
      case EPlatformerPlayerState::LOW_ATTACK: LowAttack(); break;
      case EPlatformerPlayerState::MID_ATTACK: MidAttack(); break;
      case EPlatformerPlayerState::OVERHEAD_ATTACK: HighAttack(); break;
    }
  }
}

// Called to bind functionality to input
void AFNGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AFNGBaseCharacter::LowAttack()
{
  Play(LowAttackAnimMontage);
}

void AFNGBaseCharacter::MidAttack()
{
  Play(MidAttackAnimMontage);
}

void AFNGBaseCharacter::HighAttack()
{
  Play(HighAttackAnimMontage);
}

void AFNGBaseCharacter::Play(UAnimMontage* AnimMontage)
{
  if (AnimMontage && AnimMontage != GetCurrentMontage())
  {
    PlayAnimMontage(AnimMontage);
  }
}
