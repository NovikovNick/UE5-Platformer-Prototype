// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FNGMenuHUD.generated.h"

UCLASS()
class UE5_FIGHTING_API AFNGMenuHUD : public AHUD
{
  GENERATED_BODY()

protected:
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
  TSubclassOf<UUserWidget> MenuWidgetClass;

  virtual void BeginPlay() override;
};
