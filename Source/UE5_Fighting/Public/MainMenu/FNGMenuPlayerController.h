// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FNGMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE5_FIGHTING_API AFNGMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
  virtual void BeginPlay() override;
};
