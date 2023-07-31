// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FNGPlayerController.generated.h"


UCLASS()
class UE5_FIGHTING_API AFNGPlayerController : public APlayerController
{
  GENERATED_BODY()
public:
  virtual void Tick(float DeltaSeconds) override;

protected:
  virtual void SetupInputComponent() override;
  
  UPROPERTY(EditAnywhere)
  TSubclassOf<AActor> GeneratedClass;

private:
  bool bWantsMoveLeft = false;
  bool bWantsMoveRight = false;
  bool bWantsJump = false;
  bool bWantsCrouch = false;
  bool bWantsAttack = false;
  bool bWantsBlock = false;

  void Move(float Amount);
  void Attack(bool Enable);
  void Block(bool Enable);
  void Jump(bool Enable);
  void Crouch(bool Enable);
};
