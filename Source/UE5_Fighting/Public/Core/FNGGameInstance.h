// Generic Fighting Game

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MetalHeartPlatformerTypes.h"
#include "FNGGameInstance.generated.h"

/**
 *
 */
UCLASS()
class UE5_FIGHTING_API UFNGGameInstance : public UGameInstance
{
  GENERATED_BODY()
public:

  void SetPeerEndpoint(const FEndpoint& Value) { PeerEndpoint = Value; }

  FEndpoint GetPeerEndpoint() const { return PeerEndpoint; }
  
  virtual void Shutdown() override;

private:
  FEndpoint PeerEndpoint;
};
