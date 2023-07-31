// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FNGBasePlatform.generated.h"

class UStaticMeshComponent;

UCLASS()
class UE5_FIGHTING_API AFNGBasePlatform : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AFNGBasePlatform();

protected:
  UPROPERTY(VisibleAnywhere)
  UStaticMeshComponent* BaseMesh;

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;
};
