// Generic Fighting Game

#include "FNGPlatformerFunctionLibrary.h"
#include "MetalHeartPlatformerTypes.h"
#include "api.h"
#include "schema.pb.h"

EPlatformerPlayerState Convert(ser::PlayerState state);
void Fill(const ser::Player& Src, FPlatformerPlayer& Dst);

uint8_t game_state_buf[512];
int length = 0;

void UFNGPlatformerFunctionLibrary::EvalInit(FEndpoint& PeerEndpoint)
{
  UE_LOG(LogTemp,
         Warning,
         TEXT("Init game with peer: %s:%d"),
         *PeerEndpoint.host,
         PeerEndpoint.port);
  Init({60, Endpoint{TCHAR_TO_ANSI(*PeerEndpoint.host), PeerEndpoint.port}});
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

FEndpoint UFNGPlatformerFunctionLibrary::EvalGetPublicEndpoint(int LocalPort)
{
  auto Endpoint = GetPublicEndpoint(LocalPort);
  FEndpoint res;
  res.host = UTF8_TO_TCHAR(Endpoint.remote_host);
  res.port = Endpoint.remote_port;
  return res;
}

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

  ser::GameState DeserializedGameState;
  DeserializedGameState.ParseFromArray(Buffer.Buffer, Buffer.BufferLength);

  FPlatformerGameState Res;
  Fill(DeserializedGameState.players()[0], Res.Player);
  Fill(DeserializedGameState.players()[1], Res.Enemy);
  return Res;
}

int32 UFNGPlatformerFunctionLibrary::EvalGetMicrosecondsInOneTick()
{
  return int32(getMicrosecondsInOneTick());
}

void UFNGPlatformerFunctionLibrary::EvalGetStatus() {}

void UFNGPlatformerFunctionLibrary::EvalGetErrorCode() {}

/** CONVENIENCE **/

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

void Fill(const ser::Player& Src, FPlatformerPlayer& Dst)
{
  Dst.Parameters.Position.X = Src.obj().position().x();
  Dst.Parameters.Position.Y = Src.obj().position().y();

  Dst.Parameters.Velocity.X = Src.obj().velocity().x();
  Dst.Parameters.Velocity.Y = Src.obj().velocity().y();

  Dst.Parameters.Width = Src.obj().width();
  Dst.Parameters.Height = Src.obj().height();

  Dst.IsLeftDirection = Src.left_direction();
  Dst.IsCrouch = Src.is_crouch();
  Dst.OnDamaged = Src.on_damage();
  Dst.IsBlocked = Src.state() == ser::PlayerState::BLOCK ||
                  Src.state() == ser::PlayerState::BLOCK_STUN ||
                  Src.state() == ser::PlayerState::SQUAT_BLOCK ||
                  Src.state() == ser::PlayerState::SQUAT_BLOCK_STUN;
  Dst.IsDead = Src.current_health() <= 0;

  Dst.HealthPercent = static_cast<float>(Src.current_health()) / Src.max_health();
  
  Dst.State = Convert(Src.state());
  Dst.StateFrame = Src.state_frame();
}