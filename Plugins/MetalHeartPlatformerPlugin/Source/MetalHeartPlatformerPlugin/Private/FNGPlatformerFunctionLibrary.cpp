// Generic Fighting Game

#include "FNGPlatformerFunctionLibrary.h"
#include "MetalHeartPlatformerTypes.h"
#include "api.h"
#include "schema.pb.h"

EPlatformerPlayerState Convert(ser::PlayerState state);

uint8_t game_state_buf[512];
int length = 0;

void UFNGPlatformerFunctionLibrary::EvalInit()
{
  Init({60, Endpoint{}});
}

void UFNGPlatformerFunctionLibrary::EvalSetLocation(TArray<FPlatformData>& PlatformData)
{
  TArray<Platform> Platforms;
  for (int id = 0; id < PlatformData.Num(); ++id)
  {
    Platforms.Add({id,
                   0,
                   PlatformData[id].Width,
                   PlatformData[id].Height,
                   {PlatformData[id].X, PlatformData[id].Y}});
  };

  Location location{true, {192, 704}, {96, 704}, Platforms.GetData(), Platforms.Num()};
  SetLocation(location);
}

void UFNGPlatformerFunctionLibrary::EvalGetPublicEndpoint(int local_port) {}

void UFNGPlatformerFunctionLibrary::EvalStartGame()
{
  StartGame();
}

void UFNGPlatformerFunctionLibrary::EvalStopGame() {}

void UFNGPlatformerFunctionLibrary::EvalUpdate(const bool bWantsMoveLeft,
                                               const bool bWantsMoveRight,
                                               const bool bWantsJump,
                                               const bool bWantsCrouch,
                                               const bool bWantsAttack,
                                               const bool bWantsBlock)
{
  Input input = {0};
  if (bWantsMoveLeft) input.leftPressed = true;
  if (bWantsMoveRight) input.rightPressed = true;
  if (bWantsCrouch) input.downPressed = true;
  if (bWantsJump) input.upPressed = true;
  if (bWantsAttack) input.leftMouseClicked = true;
  if (bWantsBlock) input.rightMouseClicked = true;
  Update(input);
}

FPlatformerGameState UFNGPlatformerFunctionLibrary::EvalGetState(
    FPlatformerGameBuffer& Buffer)
{
  GetState(Buffer.Buffer, &Buffer.BufferLength);

  ser::GameState dst;
  dst.ParseFromArray(Buffer.Buffer, Buffer.BufferLength);

  FPlatformerGameState res;
  res.Player.Parameters.Position.X = dst.players()[0].obj().position().x();
  res.Player.Parameters.Position.Y = dst.players()[0].obj().position().y();

  res.Player.Parameters.Velocity.X = dst.players()[0].obj().velocity().x();
  res.Player.Parameters.Velocity.Y = dst.players()[0].obj().velocity().y();

  res.Player.Parameters.Width = dst.players()[0].obj().width();
  res.Player.Parameters.Height = dst.players()[0].obj().height();

  res.Player.State = Convert(dst.players()[0].state());
  res.Player.StateFrame = dst.players()[0].state_frame();
  return res;
}

int32 UFNGPlatformerFunctionLibrary::EvalGetMicrosecondsInOneTick()
{
  return int32(getMicrosecondsInOneTick());
}

void UFNGPlatformerFunctionLibrary::EvalGetStatus() {}

void UFNGPlatformerFunctionLibrary::EvalGetErrorCode() {}

EPlatformerPlayerState Convert(ser::PlayerState state)
{
  switch (state)
  {
    case ser::PlayerState::LOW_ATTACK: return EPlatformerPlayerState::LOW_ATTACK;
    case ser::PlayerState::MID_ATTACK: return EPlatformerPlayerState::MID_ATTACK;
    case ser::PlayerState::OVERHEAD_ATTACK:
      return EPlatformerPlayerState::OVERHEAD_ATTACK;
    default: return EPlatformerPlayerState::DEATH;
  }
}