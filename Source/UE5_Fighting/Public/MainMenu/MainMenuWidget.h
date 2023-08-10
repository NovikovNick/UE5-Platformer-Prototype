// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;
class UEditableTextBox;

UCLASS()
class UE5_FIGHTING_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
  UPROPERTY(meta = (BindWidget))
  UEditableTextBox* PublicEndpointTextBox;

  UPROPERTY(meta = (BindWidget))
  UEditableTextBox* PeerEndpointTextBox;

  UPROPERTY(meta = (BindWidget))
  UButton* StartGameButton;

  UPROPERTY(meta = (BindWidget))
  UButton* ExitButton;

  virtual void NativeOnInitialized() override;

private:
  UFUNCTION()
  void OnGameStart();

  UFUNCTION()
  void OnExit();
};
