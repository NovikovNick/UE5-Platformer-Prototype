// Generic Fighting Game

#include "Core/FNGBasePlatform.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFNGBasePlatform::AFNGBasePlatform()
{
  PrimaryActorTick.bCanEverTick = false;
  BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
  SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void AFNGBasePlatform::BeginPlay()
{
  Super::BeginPlay();
  check(BaseMesh);
}
