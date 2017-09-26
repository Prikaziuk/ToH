#include "initialization.h"

#include <iostream>


int read_disk_number(){
    /*
    processing of desired disk number
    Returns:
        number of disks
        displays warning if anything extra was input
    */

    cout << "WELCOME TO THE TOWERS OF HANOI GAME\nPlease, enter a desired number of disks from 1 to 7 (one integer):\n";

    int N = 0;
    cin >> N;

    //error check
    while (cin.fail() || (N < 1 || N > 7)){
        cerr << "Error: input can not be interpreted as integer from 1 to 7.\nReenter:" << endl;
        cin.clear(); // clear the fail
        cin.ignore(1000, '\n'); // ignore first 1000 characters or before new line
        cin >> N;
    }

    // clearing cin buffer
    string extra_symbols;
    getline(cin, extra_symbols);
    if (extra_symbols != "\0"){
        cout << "`" << extra_symbols << "`" << " were ignored. Why did you enter it?\n";
    }

    return N;
}


map<string, vector<Disk>> disks_and_towers_init(int N){
    // initialization of disks on towers
    map <string, vector<Disk>> game;

    // initialization of all towers with disk of size_ = 0;
    Disk empt;
    game["t1"].push_back(empt);
    game["t2"].push_back(empt);
    game["t3"].push_back(empt);

    for (int i = N; i > 0; i--) { // filling first tower with input number of disks
        Disk temp(i);
        game["t1"].push_back(temp);
    }
    return game;
}


