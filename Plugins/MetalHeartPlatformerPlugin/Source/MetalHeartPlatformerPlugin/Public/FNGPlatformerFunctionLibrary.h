// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FNGPlatformerFunctionLibrary.generated.h"

UCLASS()
class METALHEARTPLATFORMERPLUGIN_API UFNGPlatformerFunctionLibrary
    : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void Init();  

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void SetLocation(); 

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void GetPublicEndpoint(int local_port);

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void StartGame();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void StopGame();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void Update();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void GetState();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static int32 GetMicrosecondsInOneTick();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void GetStatus();

  UFUNCTION(BlueprintCallable, Category = "Platformer Library")
  static void GetErrorCode();
};
