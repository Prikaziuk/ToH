#include "computer_solution.h"

#include <cmath> // for power
#include <iostream>
#include <string> // work with user input

using namespace std;


bool cheat(){
    /*
    auxiliary function for to_cheat_or_not_to_cheat() works with user input
    returns:
        true : if user wants to cheat (input "yes")
        false : user input anything other than "yes"
    */
    string comp;
    cout << "Would you like to see steps a computer would make? (yes or anything) \n";
    // it is better to read strings like this
    getline(cin, comp);

    return comp == "yes";
}


int min_steps(int N){
    /* calculation of minimum number of required steps to solve the game */
    return pow(2, N) - 1;
}


void computer(int N, int start, int aux, int finish) {
    /*
    recursive function from http://www.cplusplus.com/forum/beginner/130093/
    displays all steps that should be made
    */
    if (N==1){
        cout << start << " -> " << finish << endl;
    } else {
        computer(N - 1, start, finish, aux);
        cout << start << " -> " << finish << endl;
        computer(N - 1, aux, start, finish);
    }
}


void to_cheat_or_not_to_cheat(int N) {
    /*
    displays what the player has chosen: steps or minimal number of steps
    uses all functions from this .cpp file
    */
    if (cheat()){
        cout << "Here are the steps you should make:\n";
        computer(N, 1, 2, 3);
    } else {
        cout << "\nGOOD! You are not a cheater.\nHint for you: ";
        cout << "Minimal number of steps for " << N << " towers is " << min_steps(N) << "\n\n";
    }
}

