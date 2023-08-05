// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Core/FNGBaseController.h"
#include "FNGPlayerController.generated.h"

class AFNGGameState;
struct FPlatformerPlayer;

UCLASS()
class UE5_FIGHTING_API AFNGPlayerController : public AFNGBaseController
{
  GENERATED_BODY()
public:
  virtual void Tick(float DeltaSeconds) override;

protected:
  virtual void SetupInputComponent() override;
  virtual void BeginPlay() override;

private:
  void Move(float Amount);
  void Attack(bool Enable);
  void Block(bool Enable);
  void Jump(bool Enable);
  void Crouch(bool Enable);
};
