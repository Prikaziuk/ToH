#ifndef computer_solution_h
#define computer_solution_h


// auxiliary function for to_cheat_or_not_to_cheat() works with user input
bool cheat();

/*
calculation of min steps to display for the player
used by: to_cheat_or_not_to_cheat() and "game_flow.h"
*/
int min_steps(int N);

// recursive algorithm from http://www.cplusplus.com/forum/beginner/130093/
void computer(int N, int start, int aux, int finish);

// displays what the player has chosen: steps or minimal number of steps
void to_cheat_or_not_to_cheat(int N);


#endif // computer_solution_h
