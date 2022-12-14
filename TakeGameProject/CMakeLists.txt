cmake_minimum_required(VERSION 3.20)
project(TakeGameProject)

set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(TakeGameProject main.cpp source/games/game.h source/clients/game_client.h source/games/take_game/take_game_impl.h source/games/take_game/players/abstract_take_game_player.h source/games/take_game/players/human_player.h source/games/take_game/players/computer_player.h source/games/players/player.h source/games/players/abstract_player.h source/games/abstract_game.h source/IO/writer.h source/IO/console_writer.h)

# Add tests
add_subdirectory(tests)