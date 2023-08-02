// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Core/FNGBaseController.h"
#include "FNGEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class UE5_FIGHTING_API AFNGEnemyController : public AFNGBaseController
{
	GENERATED_BODY()
public:
  virtual void Tick(float DeltaSeconds) override;
};
