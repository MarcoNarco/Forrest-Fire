/*
	Creator: Marco Aguilera

	Description: This is a Forest Fire Simulation based what direction
	direction the wind is blowing based of the 4 main cardinals. The Fire
	will continue to burn until it reaches the edge.


*/
#include "FuncFireSimulation.h"

using namespace std;

int main(){

	int DayCount = 0;

	Creator();
	Intro();
	cout << "RELEASE THE INFERNO!" << endl;

	EnterForestSquare();
	//EnterForeCast();


	return 0;
}
