// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Core/FNGBasePlatform.h"
#include "FNGGameModeBase.generated.h"

// struct Platform;

UCLASS()
class UE5_FIGHTING_API AFNGGameModeBase : public AGameModeBase
{
  GENERATED_BODY()
public:
  AFNGGameModeBase();

  virtual void StartPlay() override;

  virtual void Tick(float DeltaSeconds) override;

protected:
  UPROPERTY(EditAnywhere)
  TSubclassOf<AFNGBasePlatform> PlatformClass;

  // TArray<Platform> PlatformData;
};
