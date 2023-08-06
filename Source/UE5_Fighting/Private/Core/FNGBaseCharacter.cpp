// Generic Fighting Game

#include "Core/FNGBaseCharacter.h"
#include "Core/FNGGameState.h"
#include "Camera/CameraComponent.h"
#include "Components/FNGPositionComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AFNGBaseCharacter::AFNGBaseCharacter()
{
  PrimaryActorTick.bCanEverTick = true;

  SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
  SpringArmComp->bUsePawnControlRotation = true;
  SpringArmComp->SocketOffset = FVector{0.0, 100.0, 60.0};
  SpringArmComp->SetupAttachment(GetRootComponent());

  CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
  CameraComp->SetupAttachment(SpringArmComp);

  GetCharacterMovement()->GravityScale = 0.0f;

  PositionComponent =
      CreateAbstractDefaultSubobject<UFNGPositionComponent>("PositionComponent");
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
  auto GS = GetWorld()  //
                ? Cast<AFNGGameState>(GetWorld()->GetGameState())
                : nullptr;
  if (GS)
  {
    PositionComponent->UpdateCharacterPosition(
        this,
        Is1stPlayer() ? GS->PlatformerGameState.Player : GS->PlatformerGameState.Enemy);
  }
}

// Called to bind functionality to input
void AFNGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AFNGBaseCharacter::MoveTo(float X, float Y)
{
  auto Location = GetTransform().GetLocation();
  Location.X = X;
  Location.Z = Y;
  SetActorLocation(Location);
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
