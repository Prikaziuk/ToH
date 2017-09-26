#include "print.h"

#include <iostream>


vector<Disk> insert_spaces(vector<Disk> tower, int N){
    // auxiliary function for print() to make blank lines if there are no disks
    while (tower.size() <= N + 1){ // adds empty Disks to tower
        Disk empt;
        tower.push_back(empt);
    }
    return tower;
}


void print(map<string, vector<Disk>> game, int N){
    // printing whole game to the console
    vector<Disk> tow1 = insert_spaces(game["t1"], N);
    vector<Disk> tow2 = insert_spaces(game["t2"], N);
    vector<Disk> tow3 = insert_spaces(game["t3"], N);

    for (int i = N; i > 0; i--)  {
        string s = "|" + tow1[i].make_string_disk() + "|" + tow2[i].make_string_disk() + "|" + tow3[i].make_string_disk() + "|";
        cout << s << endl;
    }
}


