// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FNGBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;

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
  UFUNCTION(BlueprintCallable)
  float GetVelocityX() const { return VelocityX; }

  void SetVelocityX(float Value) { VelocityX = Value; }

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
  float VelocityX = 0.0f;

  void Play(UAnimMontage* AnimMontage);
};
