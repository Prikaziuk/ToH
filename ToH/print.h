#ifndef print_h
#define print_h

#include "Disk.h"

#include <map>
#include <string>
#include <vector>

using namespace std;


// auxiliary function for print() to make blank lines if there are no disks
vector<Disk> insert_spaces(vector<Disk> tower, int N);

// printing whole game to the console
void print(map<string, vector<Disk>> game, int N);


#endif // print_h
