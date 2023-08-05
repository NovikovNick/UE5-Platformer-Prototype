// Generic Fighting Game

#include "MainMenu/MainMenuWidget.h"
#include "Core/FNGGameInstance.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MetalHeartPlatformerTypes.h"
#include "FNGPlatformerFunctionLibrary.h"

void UMainMenuWidget::NativeOnInitialized()
{
  Super::NativeOnInitialized();

  if (StartGameButton)
  {
    StartGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnGameStart);
  }

  if (ExitButton)
  {
    ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnExit);
  }

  if (PublicEndpointTextBox)
  {
    auto PublicEndpoint = UFNGPlatformerFunctionLibrary::EvalGetPublicEndpoint(7000);
    auto Text = PublicEndpoint.host;
    Text.Append(":");
    Text.Append(FString::FromInt(PublicEndpoint.port));
    PublicEndpointTextBox->SetText(FText::FromString(Text));
  }
}

void UMainMenuWidget::OnGameStart()
{
  if (!GetWorld()) return;

  const auto GameInstance = GetWorld()->GetGameInstance<UFNGGameInstance>();
  if (!GameInstance) return;

  auto Variable = PeerEndpointTextBox->GetText().ToString();
  FString Host;
  FString Port;
  if (Variable.Split(":", &Host, &Port))
  {
    FEndpoint PeerEndpoint;
    PeerEndpoint.host = Host;
    PeerEndpoint.port = FCString::Atoi(*Port);
    GameInstance->SetPeerEndpoint(PeerEndpoint);

    UGameplayStatics::OpenLevel(GetWorld(), "Greybox");
  }
  else
  {
    UE_LOG(LogTemp, Warning, TEXT("Wrong input"));
  };
}

void UMainMenuWidget::OnExit()
{
  UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
