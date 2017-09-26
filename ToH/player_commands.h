#ifndef player_commands_h
#define player_commands_h

#include "Disk.h"

#include <map>
#include <string>
#include <vector>

using namespace std;


// auxiliary function for command_process() to convert int to string
string convert_to_key(int tower);

// works with user command to move disk from tower 1, 2, 3
map <string, string> command_process();

//auxiliary function for move_disk() to pick last disk from each tower
Disk available_disk(map<string, vector<Disk>> & game, string tower_key);

// moves disk from tower to tower
void move_disk(map<string, vector<Disk>> & game, string from, string to, int N);


#endif // player_commands_h
