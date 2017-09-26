#ifndef initialization_h
#define initialization_h

#include "Disk.h"

#include <map>
#include <string>
#include <vector>

using namespace std;


// processing of desired disk number
int read_disk_number();

// initialization of disks on towers
map<string, vector<Disk>> disks_and_towers_init(int N);


#endif // initialization_h
