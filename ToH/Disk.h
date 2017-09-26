#ifndef Disk_h
#define Disk_h

#include <string>


class Disk{
/*
Principle object for Towers of Hanoi game.
Operates with disk size and visualization (printing to prompt)
 */
public:
// constructors
    // without parameters initializes disk size to 0 (int size_ = 0)
    Disk();

    // from 1 parameter: initializes disk size (int size_)
    Disk(int disk_number);

// member functions (methods)
    // creates string to print
    std::string make_string_disk();

    // prints string
    // void print_disk(); // was used during tuning

    int get_size();

private:
    int size_;
};


#endif // Disk
