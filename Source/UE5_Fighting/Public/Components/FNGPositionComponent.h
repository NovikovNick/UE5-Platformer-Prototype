// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FNGPositionComponent.generated.h"

struct FPlatformerPlayer;
class AFNGBaseCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE5_FIGHTING_API UFNGPositionComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  UFNGPositionComponent();

  void UpdateCharacterPosition(AFNGBaseCharacter* Actor, const FPlatformerPlayer& Char);
};
