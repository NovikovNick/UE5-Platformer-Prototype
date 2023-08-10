// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Core/FNGBasePlatform.h"
#include "MetalHeartPlatformerTypes.h"
#include "FNGGameModeBase.generated.h"


UCLASS()
class UE5_FIGHTING_API AFNGGameModeBase : public AGameModeBase
{
  GENERATED_BODY()
public:
  AFNGGameModeBase();

  virtual void StartPlay() override;

  virtual void Tick(float DeltaSeconds) override;

protected:
  UPROPERTY(EditAnywhere, Category = "Platforms")
  TSubclassOf<AFNGBasePlatform> PlatformClass;

  UPROPERTY(EditAnywhere, Category = "Platforms")
  TArray<FPlatformData> PlatformData;
};
