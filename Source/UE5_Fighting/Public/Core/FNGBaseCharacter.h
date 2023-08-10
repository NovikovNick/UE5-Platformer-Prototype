// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FNGBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;
class UFNGPositionComponent;
class UWidgetComponent;

UCLASS()
class UE5_FIGHTING_API AFNGBaseCharacter : public ACharacter
{
  GENERATED_BODY()

public:
  // Sets default values for this character's properties
  AFNGBaseCharacter();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;
  
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  UWidgetComponent* HealthWidgetComp;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
  UFNGPositionComponent* PositionComponent;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  UCameraComponent* CameraComp;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  USpringArmComponent* SpringArmComp;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
  UAnimMontage* LowAttackAnimMontage;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
  UAnimMontage* MidAttackAnimMontage;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
  UAnimMontage* HighAttackAnimMontage;

public:
  void SetVelocity(FVector Value) { Velocity = Value; }

  void SetPlayerIndex(int32 Value) { PlayerIndex = Value; }

  void SetCrouch(bool Value) { Crouch = Value; }

  void SetDamaged(bool Value) { Damaged = Value; }

  void SetBlocked(bool Value) { Blocked = Value; }

  bool Is1stPlayer() const { return PlayerIndex == 0; }

  UFUNCTION(BlueprintCallable)
  bool IsCrouch() const { return Crouch; }

  UFUNCTION(BlueprintCallable)
  bool IsDamaged() const { return Damaged; }

  UFUNCTION(BlueprintCallable)
  bool IsBlocked() const { return Blocked; }

  UFUNCTION(BlueprintCallable)
  float GetVelocityX() const { return Velocity.X; }

  UFUNCTION(BlueprintCallable)
  float GetVelocityY() const { return Velocity.Y; }

  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent* PlayerInputComponent) override;

  void MoveTo(float X, float Y);

  void LowAttack();
  void MidAttack();
  void HighAttack();

private:
  FVector Velocity;
  bool Crouch = false;
  bool Damaged = false;
  bool Blocked = false;
  int32 PlayerIndex = 0;
  bool Dead = false;

  void Play(UAnimMontage* AnimMontage);
  void OnDeath();
};
