// Generic Fighting Game

#include "Core/FNGBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Core/FNGGameState.h"
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
}

// Called to bind functionality to input
void AFNGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AFNGBaseCharacter::MoveTo(float X, float Y) {
  SetActorLocation({X, 0.0f, Y});
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
