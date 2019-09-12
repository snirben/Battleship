/*Assignment: 2
Campus : Beer Sheva
	Author : Snir Ben Yosef, ID : 307908699
	*/
#include "battleship.h"
int battleship::already_placed;
battleship::battleship()
{
	already_placed = 0; // initzilied
	

}

void battleship::setsize(int a) // set size func
{
	size = a;
}
