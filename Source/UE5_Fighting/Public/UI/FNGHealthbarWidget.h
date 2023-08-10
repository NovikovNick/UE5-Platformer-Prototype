// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FNGHealthbarWidget.generated.h"

class UProgressBar;

UCLASS()
class UE5_FIGHTING_API UFNGHealthbarWidget : public UUserWidget
{
	GENERATED_BODY()
public:
  void SetHealthPercent(float Percent);

protected:
  UPROPERTY(meta = (BindWidget))
  UProgressBar* HealthProgressBar;
};
