#include "cube.h"
#include "solver.h"


//------------------------------------------//
//---------- Mastermind Solver -------------//
//------------------------------------------//
int convert_to_base_6(int);

void MastermindSolver::testing()
{
	int pseudo_n = 6;
	set_n(4);
	
	cout << how_much_can_i_ask() << endl;
	
	what_to_ask();
	
	all_possible();
	
	
	
}

void MastermindSolver::what_to_ask()
{
	if (n > 10)
	{
	//generic_evolution_solver();
	}
	else
	{
		how_much_can_i_ask();
		//which_question_to_choose();
		//what_does_the_answer_mean();
	}
	
}



int MastermindSolver::how_much_can_i_ask()
{
	// a: alot
	int alot = 1;
	for( int i = 0; i < n; i++)
	{
		alot *= 6;
	}
	return alot;
}

string MastermindSolver::all_possible()
{
	int alot = how_much_can_i_ask() ;
	string quite_alot[alot];
	int actually = 0;
	
	for(int i = 0; i <  100; i++) //base 6 converter
	{
	actually = convert_to_base_6(i);	
	}
	
	return 0;
	
	
}

int convert_to_base_6(int i)
{
	int converted = i;
	int last_place = i%6;
	for (int e = 0;e<i; e*=6)
	{
		
		converted = i/6;
		cout << converted << last_place <<endl;
		
	}
	return converted;
	
	
}


//------------------------------------------//
//------------- Cube Solver ----------------//
//------------------------------------------//

int array[18][3][3] = {
	{{0, 0, 2}, {1, 0, 2}, {2, 0, 2}},
	{{0, 0, 1}, {1, 0, 1}, {2, 0, 1}},
	{{0, 0, 0}, {1, 0, 0}, {2, 0, 0}},
	{{0, 0, 2}, {0, 1, 2}, {0, 2, 2}},
	{{0, 0, 1}, {0, 1, 1}, {0, 2, 1}},
	{{0, 0, 0}, {0, 1, 0}, {0, 2, 0}},
	{{0, 0, 0}, {1, 0, 0}, {2, 0, 0}},
	{{0, 1, 0}, {1, 1, 0}, {2, 1, 0}},
	{{0, 2, 0}, {1, 2, 0}, {2, 2, 0}},
	{{2, 0, 0}, {2, 0, 1}, {2, 0, 2}},
	{{2, 1, 0}, {2, 1, 1}, {2, 1, 2}},
	{{2, 2, 0}, {2, 2, 1}, {2, 2, 2}},
	{{2, 0, 2}, {1, 0, 2}, {0, 0, 2}},
	{{2, 1, 2}, {1, 1, 2}, {0, 1, 2}},
	{{2, 2, 2}, {1, 2, 2}, {0, 2, 2}},
	{{0, 2, 0}, {1, 2, 0}, {2, 2, 0}},
	{{0, 2, 1}, {1, 2, 1}, {2, 2, 1}},
	{{0, 2, 2}, {1, 2, 2}, {2, 2, 2}}
};

int getMin(int d1,int d2,int d3,int d4){ //by Isabella 28.12.2019
	int min = d1;	//Berechnung des Minimums aus 4 Werten
	if(min>d2)
		min=d2;
	if(min>d3)
		min=d3;
	if(min>d4)
		min=d4;
	return min;
}

int RubiksCubeSolver::calculateManhattanDistance(Cube cube, int x, int y, int z)
{	//by Isabella 05.01.2019
	int *c1 = array[x][y];
	int center = 0;
	bool corner = false;
	Cube CubeDist(cube); //Kopie von übergebenen cube erstellen
	int cnt = 0;

	if(y==0){ // Prüfen ob Corner-Cubie oder nicht (-> edge-Cubie)
		if(z==1)
			corner = false;
		else corner = true;
	}
	else if(y==2){
		if(z==1)
			corner = false;
		else corner = true;
	}
	cout << corner << endl;

	for(int i=0; i<6; i++){ //Finden des farblich zugehörigen Mittel-Cubies
		//cout << CubeDist.returnCubie(x,y,z) << " " << CubeDist.returnCubie(i,1,1) << endl;
		if(CubeDist.returnCubie(x,y,z) == CubeDist.returnCubie(i,1,1))
			center = i;
	}
	//cout << center << endl;

	if (corner == true){ //Manhatten Distanz für Ecken (Corner-Cubies)
		int* c2 = array[center-1][0];
		int d1 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);
		c2 = array[center-1][2];
		int d2 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);
		c2 = array[center+1][0];
		int d3 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);
		c2 = array[center+1][2];
		int d4 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);

		int minimum = getMin(d1,d2,d3,d4);
		cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		cout << minimum << endl;

		return minimum;
	}
	else{	//Manhatten Distanz für Kanten (Edge-Cubies)
		int* c2 = array[center-1][1];
		int d1 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);
		c2 = array[center][0];
		int d2 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);
		c2 = array[center][2];
		int d3 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);
		c2 = array[center+1][1];
		int d4 = abs(c1[0]-c2[0]) + abs(c1[1]-c2[1]) + abs(c1[2]-c2[2]);

		int minimum = getMin(d1,d2,d3,d4);
		cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		cout << minimum << endl;

		return minimum;
	}
}

