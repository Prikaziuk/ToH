#include "game_flow.h"

#include "computer_solution.h" // for min_steps

#include <iostream>
#include <sstream>

using namespace std;


void game_flow(map<string, vector<Disk>> & game, int N){
    /*
    runs the game
    functions: command_process() and move_disk() from "action.h"
    until the game is finished;

    records valid steps and number of this steps
    when the game is over (no more disks on first and second tower ("t1" and "t2"))
        (1) informs user about it;
        (2) displays made steps and number of them;
        (3) exits;
    */
    stringstream steps; // to record steps
    int steps_number = 0; // to count steps

    while (true){
        // to quit the loop when the game is finished
        if (game["t1"].size() == 1 && game["t2"].size() == 1){ // towers 1and 2 are clear
            cout << "GAME OVER" << "\n\n";
            if (steps_number == min_steps(N)){
                cout << "CONGREATULATIONS!\nYou made it with minimal possible steps: " << steps_number << '\n';
            } else {
                cout << "You made " << steps_number << " steps while " << min_steps(N) << " were enough\n";
            }
            cout << "Your steps:\n" << steps.str();

            cout << "Press any key to exit..." << endl; // not to close window immediately
            cin.ignore(1000, '\n'); // otherwise cin.get() returns last input
            cin.get();

            break;
        }

        // processing command
        map <string, string> command = command_process();
        while (command.empty()) {
            command = command_process();
        }

        // to display steps [1] to remove 't', command is "t1"
        steps << command["from"][1] << " -> " << command["to"][1] << '\n';
        steps_number += 1;

        // move disk
        move_disk(game, command["from"], command["to"], N);
    }
}


