// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MetalHeartPlatformerTypes.h"
#include "types.h"
#include "FNGPlatformerFunctionLibrary.generated.h"

UCLASS()
class METALHEARTPLATFORMERPLUGIN_API UFNGPlatformerFunctionLibrary
    : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalInit();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalSetLocation();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalGetPublicEndpoint(int local_port);

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalStartGame();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalStopGame();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalUpdate(bool bWantsMoveLeft,
                         bool bWantsMoveRight,
                         bool bWantsJump,
                         bool bWantsCrouch,
                         bool bWantsAttack,
                         bool bWantsBlock);

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static FPlatformerGameState EvalGetState(FPlatformerGameBuffer& Buffer);

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static int32 EvalGetMicrosecondsInOneTick();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalGetStatus();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void EvalGetErrorCode();
};
