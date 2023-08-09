// Generic Fighting Game


#include "Core/FNGGameInstance.h"
#include <FNGPlatformerFunctionLibrary.h>

void UFNGGameInstance::Shutdown() {
  UFNGPlatformerFunctionLibrary::EvalStopGame();
}
