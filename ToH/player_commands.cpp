#include "player_commands.h"
#include "print.h"

#include <iostream>
#include <sstream>

string convert_to_key(int tower){
    // adding "t", because "t#" is key in the map with towers
    // converting int to string
    stringstream ss;
    ss << "t" << tower;
    return ss.str();
}


map <string, string> command_process(){
    /*
    works with user command to move disk from tower 1, 2, 3
    Returns:
        map of size 2 if the command was valid
        or
        map of size 0 (empty) the command was not valid
    */

    cout << "Enter next step FROM and TO (two integer numbers):\n";

    map <string, string> command; // to be able to return 2 strings "from" and "to"

    // reading as integers makes failure check easier
    int from_i = 0;
    int to_i = 0;
    cin >> from_i >> to_i;

    while (cin.fail()){
        cerr << "Error: input can not be interpreted as integer\nReenter:" << endl;
        cin.clear(); // clear the fail
        cin.ignore(1000, '\n'); // ignore first 1000 characters or before new linge
        cin >> from_i >> to_i;
    }

    // checking the validity of input: we have only 3 towers => only 1, 2, 3 values are valid
    if ((from_i == 1 || from_i == 2 || from_i == 3) &&
        (to_i == 1 || to_i == 2 || to_i == 3)){

        command["from"] = convert_to_key(from_i);
        command["to"] = convert_to_key(to_i);

    } else {
        cout << "An error must have occurred, FROM or TO value is not 1, 2 or 3\n";
    }
    return command;
}


Disk available_disk(map<string, vector<Disk>> & game, string tower_key){
    /*
    auxiliary function for move_disk()
    Returns upper disk for FROM and TO tower
    */
    // -1 because one is always there for beauty reasons
    int disk_index = game[tower_key].size() - 1;
    return game[tower_key][disk_index];
}


void move_disk(map<string, vector<Disk>> & game, string from, string to, int N){
    /*
    moves disk from tower to tower
    */

    Disk disk_to_move = available_disk(game, from);
    int size_from = disk_to_move.get_size();
    int size_to = available_disk(game, to).get_size();

    if (size_from == 0) { // no disk to take
        cout << "It seems like there is no disks on FROM tower\n";

    } else if (size_from < size_to || size_to == 0) { // put disk on smaller or empty tower
        game[from].pop_back();
        game[to].push_back(disk_to_move);
        print(game, N);
        cout << endl;

    } else if (size_from > size_to) { // bigger above smaller
        cout << "ILLEGAL MOVE upper disk is bigger than lower\n";

    } else { // disk sizes are equal => 1 1 , 2 2, 3 3 movements
        cout << "Static move\n";
    }
}

