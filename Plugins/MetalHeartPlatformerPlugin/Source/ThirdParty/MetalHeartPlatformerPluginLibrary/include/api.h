#ifndef PLATFORMER_FRONEND_API_H
#define PLATFORMER_FRONEND_API_H
#define EXPORT extern "C" __declspec(dllexport)

#include "types.h"

EXPORT void Init(GameContext context);

EXPORT void SetLocation(Location location);

EXPORT Endpoint GetPublicEndpoint(int local_port);

EXPORT void StartGame();

EXPORT void StopGame();

EXPORT void Update(Input input);

EXPORT void GetState(unsigned char* buf, int* length);

EXPORT long long getMicrosecondsInOneTick();

EXPORT GameStatus GetStatus();

EXPORT PlatformerErrorCode GetErrorCode();

#endif  // PLATFORMER_FRONEND_API_H