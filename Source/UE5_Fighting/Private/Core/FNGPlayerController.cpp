// Generic Fighting Game

#include "Core/FNGPlayerController.h"
#include "Core/FNGBaseCharacter.h"
#include "Core/FNGGameState.h"
#include "FNGPlatformerFunctionLibrary.h"
#include "Animation/AnimMontage.h"

void AFNGPlayerController::SetupInputComponent()
{
  Super::SetupInputComponent();
  if (!InputComponent) return;

  InputComponent->BindAxis("MoveRight", this, &AFNGPlayerController::Move);

  DECLARE_DELEGATE_OneParam(FAttackInputSignature, bool);
  InputComponent->BindAction<FAttackInputSignature>("Attack",  //
                                                    IE_Pressed,
                                                    this,
                                                    &AFNGPlayerController::Attack,
                                                    true);
  InputComponent->BindAction<FAttackInputSignature>("Attack",  //
                                                    IE_Released,
                                                    this,
                                                    &AFNGPlayerController::Attack,
                                                    false);

  DECLARE_DELEGATE_OneParam(FBlockInputSignature, bool);
  InputComponent->BindAction<FBlockInputSignature>("Block",  //
                                                   IE_Pressed,
                                                   this,
                                                   &AFNGPlayerController::Block,
                                                   true);
  InputComponent->BindAction<FBlockInputSignature>("Block",  //
                                                   IE_Released,
                                                   this,
                                                   &AFNGPlayerController::Block,
                                                   false);

  DECLARE_DELEGATE_OneParam(FCrouchInputSignature, bool);
  InputComponent->BindAction<FCrouchInputSignature>("Crouch",  //
                                                    IE_Pressed,
                                                    this,
                                                    &AFNGPlayerController::Crouch,
                                                    true);
  InputComponent->BindAction<FCrouchInputSignature>("Crouch",  //
                                                    IE_Released,
                                                    this,
                                                    &AFNGPlayerController::Crouch,
                                                    false);

  DECLARE_DELEGATE_OneParam(FJumpInputSignature, bool);
  InputComponent->BindAction<FJumpInputSignature>("Jump",  //
                                                  IE_Pressed,
                                                  this,
                                                  &AFNGPlayerController::Jump,
                                                  true);
  InputComponent->BindAction<FJumpInputSignature>("Jump",  //
                                                  IE_Released,
                                                  this,
                                                  &AFNGPlayerController::Jump,
                                                  false);
}

void AFNGPlayerController::BeginPlay()
{
  Super::BeginPlay();
  SetInputMode(FInputModeGameOnly{});
  bShowMouseCursor = false;
  if (auto FNGPlayer = Cast<AFNGBaseCharacter>(GetPawn())) FNGPlayer->SetPlayerIndex(0);
}

void AFNGPlayerController::Move(float Amount)
{
  if (auto GS = GetGameState())
  {
    GS->Input.bWantsMoveRight = Amount > 0;
    GS->Input.bWantsMoveLeft = Amount < 0;
  }
}

void AFNGPlayerController::Attack(bool Enable)
{
  if (auto GS = GetGameState()) GS->Input.bWantsAttack = Enable;
}

void AFNGPlayerController::Block(bool Enable)
{
  if (auto GS = GetGameState()) GS->Input.bWantsBlock = Enable;
}

void AFNGPlayerController::Jump(bool Enable)
{
  if (auto GS = GetGameState()) GS->Input.bWantsJump = Enable;
}

void AFNGPlayerController::Crouch(bool Enable)
{
  if (auto GS = GetGameState()) GS->Input.bWantsCrouch = Enable;
}