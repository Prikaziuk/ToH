#include "Disk.h"

#include <iostream>
#include <vector> // vector of Disks as one tower
#include <sstream>

using namespace std;


Disk::Disk() : size_(0) {} // constructor: initialization by list of initialization


Disk::Disk(int disk_number) {
    // constructor from 1 parameter: initializes disk size (int size_)
    vector <int> disk_size = {0, 1, 3, 5, 7, 9, 11, 13}; // list of sizes for beauty reasons
    size_ = disk_size[disk_number];
}


string Disk::make_string_disk() {
    // creates string to print

    // maximum number of disks - 7 => 13'*' symbols + 2 spaces (left and right) => string.size() == 15;
    const int s_length = 15;

    int left_spaces = (s_length - size_) / 2;

    stringstream disk_string;
    disk_string << string(left_spaces, ' ') << string(size_, '*'); //<< '\n';

    // for right spaces
    int length = disk_string.str().size();
    disk_string << string(s_length - length, ' ');

    return disk_string.str();
}


//void Disk::print_disk() {
//    // may be from tower
//    cout << make_string_disk() << endl;
//}


int Disk::get_size(){
    // returns value from private field
    return size_;
}


