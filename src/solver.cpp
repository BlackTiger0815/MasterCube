#include "cube.h"
#include "solver.h"

#define MAXMOVES 10 //Maximale Anzal an Drehungen die durchgeführt werden darf 

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

template <class T>
T getMin(T d1,T d2,T d3,T d4){ //by Isabella 28.12.2019
	T min = d1;	//Berechnung des Minimums aus 4 Werten
	if(min>d2)
		min=d2;
	if(min>d3)
		min=d3;
	if(min>d4)
		min=d4;
	return min;
}

template <class T>
T getMax(T d1,T d2,T d3,T d4){ //by Isabella 05.01.2020
	T max = d1;	//Berechnung des Maximums aus 4 Werten
	if(max<d2)
		max=d2;
	if(max<d3)
		max=d3;
	if(max<d4)
		max=d4;
	return max;
}

int RubiksCubeSolver::calculateManhattanDistance(Cube cube, int x, int y, int z)
{	//by Isabella 05.01.2019
	//In Anlehnungn an https://github.com/FarhanShoukat/Rubiks-Cube-Solver/blob/master/RubixcubeSolution.py
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
	//cout << "Corner? True/False " << corner << endl;

	for(int i=0; i<6; i++){ //Finden des farblich zugehörigen Mittel-Cubies
		//cout << CubeDist.returnCubie(x,y,z) << " " << CubeDist.returnCubie(i,1,1) << endl;
		if(CubeDist.returnCubie(x,y,z) == CubeDist.returnCubie(i,1,1))
			center = i;
	}
	//cout << "Center at side "<< center << endl;

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
		//cout << "Distanz Cubie: "<< d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		//cout << "Min Distanz: "<< minimum << endl << endl;

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
		//cout << "Distanz Cubie: " << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		//cout << "Min Distanz: " << minimum << endl << endl;

		return minimum;
	}
}

float RubiksCubeSolver::max_CornerEdge_sum(Cube c){
	//by Isabella 06.01.2019
	int corners = 2;
	int edges = 5;

	for(int i=0; i<6; i++){	//Seite
		for(int j=0; j<3; j++){	//Zeile
			if( (i*3+j)%3 == 0 || (i*3+j)%3 == 2){ //Immer wenn corners vorhanden sind
				corners = corners + calculateManhattanDistance(c, i, j, 0) + calculateManhattanDistance(c, i, j, 2);
				edges = edges + calculateManhattanDistance(c, i, j, 1);
			}
			else{ //Nur edges in Zeile vorhanden
				edges = edges + calculateManhattanDistance(c, i, j, 0) + calculateManhattanDistance(c, i, j, 2);
			}
		}
	}
	return getMax(corners/12, edges/8, 0,0);
}

float RubiksCubeSolver::calculateNumUnsolvedCubies(Cube c, bool admissible){
	//by Isabella 06.01.2019
	//in Anlehnung an https://github.com/Jeff-A-Martin/RubiksCubeSolver/blob/master/src/Goal_Oriented_IDAStar_Solver.java
	float num = 0;
	for(int i=0; i<6; i++){ //Seite
		for(int j=0; j<3; j++){ //Zeile
			for(int k=0; k<3; k++){ //Cubie
				if(c.returnCubie(i,j,k) != c.returnCubie(i,1,1)){
				//Wenn aktuelle CubieFarbe nicht MittelCubie -> unsolved
					num++;
				}
			}
		}
	}
	return (admissible) ? num/8 : num;
}

Cube RubiksCubeSolver::performMove(Cube c, int i){ //by Isabella 16.01.2020
	switch(i){
		case 1:
			c.r();
			return c;
		case 2:
			c.ri();
			return c;
		case 3:
			c.l();
			return c;
		case 4:
			c.li();
			return c;
		case 5:
			c.u();
			return c;
		case 6:
			c.ui();
			return c;
		case 7:
			c.d();
			return c;
		case 8:
			c.di();
			return c;
		case 9:
			c.f();
			return c;
		case 10:
			c.fi();
			return c;
		case 11:
			c.b();
			return c;
		case 12:
			c.bi();
			return c;
		default:
			;//nothing
	}
}

double RubiksCubeSolver::IDAstarAlgorithm(Cube scrambledCube, int cost, int lastMove){ ////by Isabella 16.01.2020
	//int cost = 0;
	float heuritic = calculateNumUnsolvedCubies(scrambledCube, 1);
	cout << "heuritic " << heuritic << endl;
	if(heuritic == 0) return -1; //Cube ist bereits gelöst
	float f = cost + heuritic;	//Geschätzte Kosten für den Cube
	if(cost>50) return -10; //Error
	int cntStates = 0;
	Cube movedCube;

	//int last_move = 0;

	for(int i=1; i<MAXMOVES+1; i++){
		//if(i >= 0 && (i/3 == last_move/3)) continue;
		cntStates ++;
		lastMove = lastMove++;
		movedCube = performMove(scrambledCube, i);
		movedCube.printMoves();
		movedCube.printCube();

		if(calculateNumUnsolvedCubies(scrambledCube, 1) > heuritic){
			//undo moves
		}
		else{
			//neuer move probieren
		}

		//double t = IDAstarAlgorithm(scrambledCube, cost+1, lastMove); //NICHT REKURSIV LÖSEN!!!
		//if(calculateNumUnsolvedCubies(scrambledCube,1) > heuritic){

	}
}
