#ifndef PLATFORMER_TYPES_H
#define PLATFORMER_TYPES_H

enum GameStatus {
  INVALID = -1,
  RUN = 0,
  SYNC = 1,
  STOPED = 2,
};

enum PlatformerErrorCode {
  OK = 0,
  UNEXPECTED_ERROR = 1,
  UNABLE_TO_PARSE_STUN_RESPONSE = 2,
};

struct Input {
  bool leftPressed, rightPressed, upPressed, downPressed;
  bool leftMouseClicked, rightMouseClicked;
};

struct Endpoint {
  const char* remote_host;
  const int remote_port;
};

struct Point {
  int x, y;
};

struct Platform {
  int id, type, width, height;
  Point position;
};

struct Location {
  bool is_1st_player;
  Point position_1st_player, position_2nd_player;
  Platform* platforms;
  unsigned long long platforms_count;
};

struct GameContext {
  int tick_rate;
  Endpoint peer_endpoint;
};

#endif  // PLATFORMER_TYPES_H