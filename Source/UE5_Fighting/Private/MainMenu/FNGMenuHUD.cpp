// Generic Fighting Game

#include "MainMenu/FNGMenuHUD.h"
#include "Blueprint/UserWidget.h"

void AFNGMenuHUD::BeginPlay()
{
  Super::BeginPlay();
  
  if (const auto Widget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass))
  {
    Widget->AddToViewport();
  }
}
