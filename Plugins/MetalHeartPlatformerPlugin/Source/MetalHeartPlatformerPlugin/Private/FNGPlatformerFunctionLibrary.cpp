// Generic Fighting Game

#include "FNGPlatformerFunctionLibrary.h"
#include "api.h"

void UFNGPlatformerFunctionLibrary::Init() {}

void UFNGPlatformerFunctionLibrary::SetLocation() {}

void UFNGPlatformerFunctionLibrary::GetPublicEndpoint(int local_port) {}

void UFNGPlatformerFunctionLibrary::StartGame() {}

void UFNGPlatformerFunctionLibrary::StopGame() {}

void UFNGPlatformerFunctionLibrary::Update() {}

void UFNGPlatformerFunctionLibrary::GetState() {}

int32 UFNGPlatformerFunctionLibrary::GetMicrosecondsInOneTick()
{
  return int32(getMicrosecondsInOneTick());
}

void UFNGPlatformerFunctionLibrary::GetStatus() {}

void UFNGPlatformerFunctionLibrary::GetErrorCode() {}
