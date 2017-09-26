#ifndef game_flow_h
#define game_flow_h

#include "player_commands.h" // to include map, string, vector and Disk


/* runs the game
    functions: command_process() and move_disk() from "player_commands.h"
    until the game is finished
*/
void game_flow(map<string, vector<Disk>> & game, int N);


#endif // game_flow_h
