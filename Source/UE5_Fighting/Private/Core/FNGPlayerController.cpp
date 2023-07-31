// Generic Fighting Game

#include "Core/FNGPlayerController.h"
#include "Core/FNGBaseCharacter.h"
#include "FNGPlatformerFunctionLibrary.h"
#include "Animation/AnimMontage.h"

void AFNGPlayerController::Tick(float DeltaSeconds)
{
  UFNGPlatformerFunctionLibrary::EvalUpdate(bWantsMoveLeft,
                                            bWantsMoveRight,
                                            bWantsJump,
                                            bWantsCrouch,
                                            bWantsAttack,
                                            bWantsBlock);
}

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

void AFNGPlayerController::Move(float Amount)
{
  bWantsMoveLeft = Amount < 0;
  bWantsMoveRight = Amount > 0;
}

void AFNGPlayerController::Attack(bool Enable)
{
  bWantsAttack = Enable;
}

void AFNGPlayerController::Block(bool Enable)
{
  bWantsBlock = Enable;
}

void AFNGPlayerController::Jump(bool Enable)
{
  bWantsJump = Enable;
}

void AFNGPlayerController::Crouch(bool Enable)
{
  bWantsCrouch = Enable;
}
