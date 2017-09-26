#include "computer_solution.h" // to_cheat_or_not_to_cheat()
//#include "Disk.h" // is already included in all header files
#include "game_flow.h"
#include "initialization.h" // read_disk_number() and disks_and_towers_init()
//#include "player_commands.h" // is not needed here because included and used only in game_flow.h
#include "print.h" // print()


int main(){
// "initialization.h"
    // reading disks (with processing)
    int N = read_disk_number();
    // initializing towers and disks: all disks on the first tower
    map<string, vector<Disk>> game = disks_and_towers_init(N);

// "print.h"
    // displaying initial position for the player
    print(game, N);

// "computer_solution.h"
    // opportunity to get all steps from computer
    to_cheat_or_not_to_cheat(N);

// "game_flow.h" (using "player_commands.h")
    // movements
    game_flow(game, N);

    return 0;
}


