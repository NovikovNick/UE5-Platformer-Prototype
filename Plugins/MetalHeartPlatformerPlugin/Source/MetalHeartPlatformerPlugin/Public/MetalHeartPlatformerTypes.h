#pragma once

#include "MetalHeartPlatformerTypes.generated.h"

USTRUCT(BlueprintType)
struct FPlatformerGameBuffer
{
  GENERATED_USTRUCT_BODY()

  uint8* Buffer;

  int32 BufferLength;
};

UENUM(BlueprintType)
enum class EPlatformerPlayerState : uint8
{
  IDLE = 0,
  RUN,
  JUMP,
  FALLING,
  LANDING,
  SQUAT,
  OVERHEAD_ATTACK,
  MID_ATTACK,
  LOW_ATTACK,
  BLOCK,
  SQUAT_BLOCK,
  HIT_STUN,
  BLOCK_STUN,
  SQUAT_BLOCK_STUN,
  DEATH,
};

UENUM(BlueprintType)
enum class EPlatformerPlayerAttackPhase : uint8
{
  STARTUP = 0,
  ACTIVE,
  RECOVERY,
  NONE,
};

USTRUCT(BlueprintType)
struct FPlatformerGameObject
{
  GENERATED_USTRUCT_BODY()

  int32 Width, Height;
  FVector2D Position, Velocity;
};

USTRUCT(BlueprintType)
struct FPlatformerPlayer
{
  GENERATED_USTRUCT_BODY()

  FPlatformerGameObject Parameters;

  EPlatformerPlayerState State;
  int32 StateFrame;
  bool IsLeftDirection;
  bool IsCrouch;
  bool OnDamaged;
  bool IsBlocked;
  EPlatformerPlayerAttackPhase AttackPhase;
};

USTRUCT(BlueprintType)
struct FPlatformerGameState
{
  GENERATED_USTRUCT_BODY()

  FPlatformerPlayer Player, Enemy;
};

USTRUCT(BlueprintType)
struct FInputData
{
  GENERATED_USTRUCT_BODY()

  bool bWantsMoveLeft = false;
  bool bWantsMoveRight = false;
  bool bWantsJump = false;
  bool bWantsCrouch = false;
  bool bWantsAttack = false;
  bool bWantsBlock = false;
};

USTRUCT(BlueprintType)
struct FPlatformData
{
  GENERATED_USTRUCT_BODY()

public:
  UPROPERTY(EditAnywhere, Category = "General")
  int32 X;
  UPROPERTY(EditAnywhere, Category = "General")
  int32 Y;
  UPROPERTY(EditAnywhere, Category = "General")
  int32 Width;
  UPROPERTY(EditAnywhere, Category = "General")
  int32 Height;
};

USTRUCT(BlueprintType)
struct FEndpoint
{
  GENERATED_USTRUCT_BODY()

  FString host;
  int32 port;
};

