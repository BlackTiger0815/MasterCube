#include "cube.h"


//-----------------------------------------------//
//---------------Allgemeine Funktionen---------------//
//-----------------------------------------------//

char numbers_to_color(int number)
{
	char color[] = "wgrboy"; //white green red blue orange yellow
	return color[number];	
}

int color_to_number(char color)
{
	switch (color)
	{
	case 'w':
		return 0;
		
	case 'g':
		return 1;
		
	case 'r':
		return 2;
		
	case 'b':
		return 3;
		
	case 'o':
		return 4;
		
	case 'y':
		return 5;
		
	default:
		//cout << "you took a wrong turn" <<endl;
		return -1;
	}
}


//-----------------------------------------------//
//---------------Globale Drehungen---------------//
//-----------------------------------------------//
void Cube::globalRotationR(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=1; i<5; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==4){
					_cube[i-3][j][k]=_old[i][j][k];
				}
				else{
					_cube[i+1][j][k]=_old[i][j][k];
				}
			}
		}
	}

	//corners der oberseite
	_cube[0][0][0] = _old[0][2][0];
	_cube[0][2][0] = _old[0][2][2];
	_cube[0][2][2] = _old[0][0][2];
	_cube[0][0][2] = _old[0][0][0];
	//edges der oberseite
	_cube[0][0][1] = _old[0][1][0];
	_cube[0][1][0] = _old[0][2][1];
	_cube[0][2][1] = _old[0][1][2];
	_cube[0][1][2] = _old[0][0][1];
	//corners der unterseite
	_cube[5][0][0] = _old[5][2][0];
	_cube[5][2][0] = _old[5][2][2];
	_cube[5][2][2] = _old[5][0][2];
	_cube[5][0][2] = _old[5][0][0];
	//edges der unterseite
	_cube[5][0][1] = _old[5][1][0];
	_cube[5][1][0] = _old[5][2][1];
	_cube[5][2][1] = _old[5][1][2];
	_cube[5][1][2] = _old[5][0][1];

	moves += "gR ";
}

void Cube::globalRotationL(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=1; i<5; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==1){
					_cube[i+3][j][k]=_old[i][j][k];
				}
				else{
					_cube[i-1][j][k]=_old[i][j][k];
				}
			}
		}
	}
	//corners der oberseite
	_cube[0][0][0] = _old[0][0][2];
	_cube[0][0][2] = _old[0][2][2];
	_cube[0][2][2] = _old[0][2][0];
	_cube[0][2][0] = _old[0][0][0];
	//edges der oberseite
	_cube[0][0][1] = _old[0][1][2];
	_cube[0][1][0] = _old[0][0][1];
	_cube[0][2][1] = _old[0][1][0];
	_cube[0][1][2] = _old[0][2][1];

	moves += "gL ";
}

void Cube::globalRotationD(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==0) _cube[i+2][j][k] = _old[i][j][k];
				if(i==2) _cube[i+3][j][k] = _old[i][j][k];
				if(i==4) _cube[i-4][j][k] = _old[i][j][k];
				if(i==5) _cube[i-1][j][k] = _old[i][j][k];
			}
		}
	}
	//corners linken Seite -> drehung nach rechts
	_cube[1][0][0] = _old[1][2][0];
	_cube[1][2][0] = _old[1][2][2];
	_cube[1][2][2] = _old[1][0][2];
	_cube[1][0][2] = _old[1][0][0];
	//edges der linken Seite -> drehung nach rechts
	_cube[1][0][1] = _old[1][1][0];
	_cube[1][1][0] = _old[1][2][1];
	_cube[1][2][1] = _old[1][1][2];
	_cube[1][1][2] = _old[1][0][1];
	//corners der rechten Seite - > Dreheung nach links
	_cube[3][0][0] = _old[3][0][2];
	_cube[3][0][2] = _old[3][2][2];
	_cube[3][2][2] = _old[3][2][0];
	_cube[3][2][0] = _old[3][0][0];
	//edges der rechten Seite - > Dreheung nach links
	_cube[3][0][1] = _old[3][1][2];
	_cube[3][1][0] = _old[3][0][1];
	_cube[3][2][1] = _old[3][1][0];
	_cube[3][1][2] = _old[3][2][1];

	moves += "gD ";
}

void Cube::globalRotationU(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==0) _cube[i+4][j][k] = _old[i][j][k];
				if(i==2) _cube[i-2][j][k] = _old[i][j][k];
				if(i==4) _cube[i+1][j][k] = _old[i][j][k];
				if(i==5) _cube[i-3][j][k] = _old[i][j][k];
			}
		}
	}
	//corners der linken Seite - > Dreheung nach links
	_cube[1][0][0] = _old[1][0][2];
	_cube[1][0][2] = _old[1][2][2];
	_cube[1][2][2] = _old[1][2][0];
	_cube[1][2][0] = _old[1][0][0];
	//edges der linken Seite - > Dreheung nach links
	_cube[1][0][1] = _old[1][1][2];
	_cube[1][1][0] = _old[1][0][1];
	_cube[1][2][1] = _old[1][1][0];
	_cube[1][1][2] = _old[1][2][1];
	//corners rechten Seite -> drehung nach rechts
	_cube[3][0][0] = _old[3][2][0];
	_cube[3][2][0] = _old[3][2][2];
	_cube[3][2][2] = _old[3][0][2];
	_cube[3][0][2] = _old[3][0][0];
	//edges der rechten Seite -> drehung nach rechts
	_cube[3][0][1] = _old[3][1][0];
	_cube[3][1][0] = _old[3][2][1];
	_cube[3][2][1] = _old[3][1][2];
	_cube[3][1][2] = _old[3][0][1];

	moves += "gU ";
}


//-----------------------------------------------//
//---------------------Moves---------------------//
//-----------------------------------------------//

void Cube::r()
{
	if (last() == "r  ")
	{
		removeLast();
		moves += "r2 ";
	}
	else if (last() == "r2 ")
	{
		removeLast();
		moves += "ri ";
	}
	else if (last() == "ri ")
	{
		removeLast();
	}
	else
	{
		moves += "r  ";
	}

	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][i][2] = _old[5][i][2];
		_cube[0][i][2] = _old[2][i][2];
		_cube[4][i][0] = _old[0][2 - i][2];
		_cube[5][i][2] = _old[4][2 - i][0];
	}
	_cube[3][0][2] = _old[3][0][0];
	_cube[3][2][2] = _old[3][0][2];
	_cube[3][2][0] = _old[3][2][2];
	_cube[3][0][0] = _old[3][2][0];

	_cube[3][1][2] = _old[3][0][1];
	_cube[3][2][1] = _old[3][1][2];
	_cube[3][1][0] = _old[3][2][1];
	_cube[3][0][1] = _old[3][1][0];
}

void Cube::ri()
{
	if (last() == "ri ")
	{
		removeLast();
		moves += "r2 ";
	}
	else if (last() == "r2 ")
	{
		removeLast();
		moves += "r  ";
	}
	else if (last() == "r  ")
	{
		removeLast();
	}
	else
	{
		moves += "ri ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[5][i][2] = _old[2][i][2];
		_cube[2][i][2] = _old[0][i][2];
		_cube[0][2 - i][2] = _old[4][i][0];
		_cube[4][2 - i][0] = _old[5][i][2];
	}
	_cube[3][0][0] = _old[3][0][2];
	_cube[3][0][2] = _old[3][2][2];
	_cube[3][2][2] = _old[3][2][0];
	_cube[3][2][0] = _old[3][0][0];

	_cube[3][0][1] = _old[3][1][2];
	_cube[3][1][2] = _old[3][2][1];
	_cube[3][2][1] = _old[3][1][0];
	_cube[3][1][0] = _old[3][0][1];
}

void Cube::l()
{
	if (last() == "l  ")
	{
		removeLast();
		moves += "l2 ";
	}
	else if (last() == "l2 ")
	{
		removeLast();
		moves += "li ";
	}
	else if (last() == "li ")
	{
		removeLast();
	}
	else
	{
		moves += "l  ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[5][i][0] = _old[2][i][0];
		_cube[2][i][0] = _old[0][i][0];
		_cube[0][i][0] = _old[4][2 - i][2];
		_cube[4][2 - i][2] = _old[5][i][0];
	}
	_cube[1][0][2] = _old[1][0][0];
	_cube[1][2][2] = _old[1][0][2];
	_cube[1][2][0] = _old[1][2][2];
	_cube[1][0][0] = _old[1][2][0];

	_cube[1][1][2] = _old[1][0][1];
	_cube[1][2][1] = _old[1][1][2];
	_cube[1][1][0] = _old[1][2][1];
	_cube[1][0][1] = _old[1][1][0];
}

void Cube::li()
{
	if (last() == "li ")
	{
		removeLast();
		moves += "l2 ";
	}
	else if (last() == "l2 ")
	{
		removeLast();
		moves += "l  ";
	}
	else if (last() == "l  ")
	{
		removeLast();
	}
	else
	{
		moves += "li ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][i][0] = _old[5][i][0];
		_cube[0][i][0] = _old[2][i][0];
		_cube[4][i][2] = _old[0][2 - i][0];
		_cube[5][i][0] = _old[4][2 - i][2];
	}
	_cube[1][0][0] = _old[1][0][2];
	_cube[1][0][2] = _old[1][2][2];
	_cube[1][2][2] = _old[1][2][0];
	_cube[1][2][0] = _old[1][0][0];

	_cube[1][0][1] = _old[1][1][2];
	_cube[1][1][2] = _old[1][2][1];
	_cube[1][2][1] = _old[1][1][0];
	_cube[1][1][0] = _old[1][0][1];
}

void Cube::u()
{
	if (last() == "u  ")
	{
		removeLast();
		moves += "u2 ";
	}
	else if (last() == "u2 ")
	{
		removeLast();
		moves += "ui ";
	}
	else if (last() == "ui ")
	{
		removeLast();
	}
	else
	{
		moves += "u  ";
	}

	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][0][i] = _old[2][0][i];
		_cube[4][0][i] = _old[1][0][i];
		_cube[3][0][i] = _old[4][0][i];
		_cube[2][0][i] = _old[3][0][i];
	}
	_cube[0][0][0] = _old[0][2][0];
	_cube[0][0][2] = _old[0][0][0];
	_cube[0][2][2] = _old[0][0][2];
	_cube[0][2][0] = _old[0][2][2];

	_cube[0][0][1] = _old[0][1][0];
	_cube[0][1][2] = _old[0][0][1];
	_cube[0][2][1] = _old[0][1][2];
	_cube[0][1][0] = _old[0][2][1];
}

void Cube::ui()
{
	if (last() == "ui ")
	{
		removeLast();
		moves += "u2 ";
	}
	else if (last() == "u2 ")
	{
		removeLast();
		moves += "u  ";
	}
	else if (last() == "u  ")
	{
		removeLast();
	}
	else
	{
		moves += "ui ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][0][i] = _old[1][0][i];
		_cube[1][0][i] = _old[4][0][i];
		_cube[4][0][i] = _old[3][0][i];
		_cube[3][0][i] = _old[2][0][i];
	}
	_cube[0][2][0] = _old[0][0][0];
	_cube[0][0][0] = _old[0][0][2];
	_cube[0][0][2] = _old[0][2][2];
	_cube[0][2][2] = _old[0][2][0];

	_cube[0][1][0] = _old[0][0][1];
	_cube[0][0][1] = _old[0][1][2];
	_cube[0][1][2] = _old[0][2][1];
	_cube[0][2][1] = _old[0][1][0];
}

void Cube::d()
{
	if (last() == "d  ")
	{
		removeLast();
		moves += "d2 ";
	}
	else if (last() == "d2 ")
	{
		removeLast();
		moves += "di ";
	}
	else if (last() == "di ")
	{
		removeLast();
	}
	else
	{
		moves += "d  ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][2][i] = _old[1][2][i];
		_cube[1][2][i] = _old[4][2][i];
		_cube[4][2][i] = _old[3][2][i];
		_cube[3][2][i] = _old[2][2][i];
	}
	_cube[5][0][0] = _old[5][2][0];
	_cube[5][0][2] = _old[5][0][0];
	_cube[5][2][2] = _old[5][0][2];
	_cube[5][2][0] = _old[5][2][2];

	_cube[5][0][1] = _old[5][1][0];
	_cube[5][1][2] = _old[5][0][1];
	_cube[5][2][1] = _old[5][1][2];
	_cube[5][1][0] = _old[5][2][1];
}

void Cube::di()
{
	if (last() == "di ")
	{
		removeLast();
		moves += "d2 ";
	}
	else if (last() == "d2 ")
	{
		removeLast();
		moves += "d  ";
	}
	else if (last() == "d  ")
	{
		removeLast();
	}
	else
	{
		moves += "di ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][2][i] = _old[2][2][i];
		_cube[4][2][i] = _old[1][2][i];
		_cube[3][2][i] = _old[4][2][i];
		_cube[2][2][i] = _old[3][2][i];
	}
	_cube[5][2][0] = _old[5][0][0];
	_cube[5][0][0] = _old[5][0][2];
	_cube[5][0][2] = _old[5][2][2];
	_cube[5][2][2] = _old[5][2][0];

	_cube[5][1][0] = _old[5][0][1];
	_cube[5][0][1] = _old[5][1][2];
	_cube[5][1][2] = _old[5][2][1];
	_cube[5][2][1] = _old[5][1][0];
}

void Cube::f()
{
	if (last() == "f  ")
	{
		removeLast();
		moves += "f2 ";
	}
	else if (last() == "f2 ")
	{
		removeLast();
		moves += "fi ";
	}
	else if (last() == "fi ")
	{
		removeLast();
	}
	else
	{
		moves += "f  ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[0][2][i] = _old[1][2 - i][2];
		_cube[3][i][0] = _old[0][2][i];
		_cube[5][0][2 - i] = _old[3][i][0];
		_cube[1][2 - i][2] = _old[5][0][2 - i];
	}
	_cube[2][0][2] = _old[2][0][0];
	_cube[2][2][2] = _old[2][0][2];
	_cube[2][2][0] = _old[2][2][2];
	_cube[2][0][0] = _old[2][2][0];

	_cube[2][1][2] = _old[2][0][1];
	_cube[2][2][1] = _old[2][1][2];
	_cube[2][1][0] = _old[2][2][1];
	_cube[2][0][1] = _old[2][1][0];
}

void Cube::fi()
{
	if (last() == "fi ")
	{
		removeLast();
		moves += "f2 ";
	}
	else if (last() == "f2 ")
	{
		removeLast();
		moves += "f  ";
	}
	else if (last() == "f  ")
	{
		removeLast();
	}
	else
	{
		moves += "fi ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][i][2] = _old[0][2][2 - i];
		_cube[0][2][2 - i] = _old[3][2 - i][0];
		_cube[3][2 - i][0] = _old[5][0][i];
		_cube[5][0][i] = _old[1][i][2];
	}
	_cube[2][0][0] = _old[2][0][2];
	_cube[2][0][2] = _old[2][2][2];
	_cube[2][2][2] = _old[2][2][0];
	_cube[2][2][0] = _old[2][0][0];

	_cube[2][0][1] = _old[2][1][2];
	_cube[2][1][2] = _old[2][2][1];
	_cube[2][2][1] = _old[2][1][0];
	_cube[2][1][0] = _old[2][0][1];
}

void Cube::b()
{
	if (last() == "b  ")
	{
		removeLast();
		moves += "b2 ";
	}
	else if (last() == "b2 ")
	{
		removeLast();
		moves += "bi ";
	}
	else if (last() == "bi ")
	{
		removeLast();
	}
	else
	{
		moves += "b  ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][2 - i][0] = _old[0][0][i];
		_cube[0][0][i] = _old[3][i][2];
		_cube[3][i][2] = _old[5][2][2 - i];
		_cube[5][2][2 - i] = _old[1][2 - i][0];
	}
	_cube[4][0][2] = _old[4][0][0];
	_cube[4][2][2] = _old[4][0][2];
	_cube[4][2][0] = _old[4][2][2];
	_cube[4][0][0] = _old[4][2][0];

	_cube[4][1][2] = _old[4][0][1];
	_cube[4][2][1] = _old[4][1][2];
	_cube[4][1][0] = _old[4][2][1];
	_cube[4][0][1] = _old[4][1][0];
}

void Cube::bi()
{
	if (last() == "bi ")
	{
		removeLast();
		moves += "b2 ";
	}
	else if (last() == "b2 ")
	{
		removeLast();
		moves += "b  ";
	}
	else if (last() == "b  ")
	{
		removeLast();
	}
	else
	{
		moves += "bi ";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[0][0][i] = _old[1][2 - i][0];
		_cube[3][i][2] = _old[0][0][i];
		_cube[5][2][2 - i] = _old[3][i][2];
		_cube[1][2 - i][0] = _old[5][2][2 - i];
	}
	_cube[4][0][0] = _old[4][0][2];
	_cube[4][0][2] = _old[4][2][2];
	_cube[4][2][2] = _old[4][2][0];
	_cube[4][2][0] = _old[4][0][0];

	_cube[4][0][1] = _old[4][1][2];
	_cube[4][1][2] = _old[4][2][1];
	_cube[4][2][1] = _old[4][1][0];
	_cube[4][1][0] = _old[4][0][1];
}


void Cube::solveTopCross()
{
	moveTopEdges();
	//look for the 4 yellow edges
	for (int i = 1; i < 5; i++)
	{
		int side = 0; //side that the yellow sticker is on
		int pos = 0; //position (1-4) of the yellow sticker
		findNextTopEdge(side, pos);
		int numTurns = 0; //keeps track of how many times we turn the cube to put pieces on the bottom layer so we can undo the turns
		if (side == 1)
		{
			while (_cube[5][1][0] == 0)
			{
				d();
			}
			while (_cube[0][1][0] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				l();
				l();
			}
			else if (pos == 2)
			{
				l();
			}
			else if (pos == 4)
			{
				li();
			}
		}
		else if (side == 2)
		{
			while (_cube[5][0][1] == 0)
			{
				d();
			}
			while (_cube[0][2][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				f();
				f();
			}
			else if (pos == 2)
			{
				f();
			}
			else if (pos == 4)
			{
				fi();
			}
			di();
		}
		else if (side == 3)
		{
			while (_cube[5][1][2] == 0)
			{
				d();
			}
			while (_cube[0][1][2] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				r();
				r();
			}
			else if (pos == 2)
			{
				r();
			}
			else if (pos == 4)
			{
				ri();
			}
			d();
			d();
		}
		else if (side == 4)
		{
			while (_cube[5][2][1] == 0)
			{
				d();
			}
			while (_cube[0][0][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				b();
				b();
			}
			else if (pos == 2)
			{
				b();
			}
			else if (pos == 4)
			{
				bi();
			}
			d();
		}
		else if (side == 5)
		{
			for (int j = 0; j < 4 - pos; j++)
			{
				d();
			}
		}
		for (int j = 0; j < numTurns; j++)
		{
			ui();
		}
		if (side == 5) //algorithm for when the sticker is on the bottom
		{
			int color = _cube[1][2][1];
			for (int a = 1; a < color; a++) //set-up so that the edge goes into the right spot
			{
				u();
			}
			l();
			l();
			for (int a = 1; a < color; a++) //undo set-up
			{
				ui();
			}
		}
		else //algorithm for when th esticker is not on the bottom
		{
			int color = _cube[5][1][0];
			if (color < 4) //set-up so that the sticker goes into the right spot
			{
				for (int a = 1; a < color + 1; a++)
				{
					u();
				}
			}
			l();
			bi();
			li();
			if (color < 4) //undo set-up
			{
				for (int a = 1; a < color + 1; a++)
				{
					ui();
				}
			}
		}
	}
}

void Cube::moveTopEdges() //move all yellow edge stickers on top to the bottom
{
	for (int i = 0; i < 4; i++)
	{
		if (_cube[0][2][1] == 0)
		{
			while (_cube[5][0][1] == 0)
			{
				d();
			}
			f();
			f();
		}
		u();
	}
}

void Cube::findNextTopEdge(int & s, int & p)
{
	for (s = 1; s < 6; s++)
	{
		if (_cube[s][0][1] == 0)
		{
			p = 1;
			break;
		}
		else if (_cube[s][1][2] == 0)
		{
			p = 2;
			break;
		}
		else if (_cube[s][2][1] == 0)
		{
			p = 3;
			break;
		}
		else if (_cube[s][1][0] == 0)
		{
			p = 4;
			break;
		}
	}
}

void Cube::solveTopCorners()
{
	moveTopCorners();
	for (int i = 1; i < 5; i++)
	{
		bool bottom = false; //holds whether the yellow sticker is on the bottom face
		bool rig = false; //holds whether the yellow sticker is on the right face
		int side = 0; //what face the yellow sticker is on
		int pos = 0; //which corner the piece is in
		findNextTopCorner(side, pos);
		if (side < 5) //puts the corner in the back bottom right corner
		{
			if (pos == 2)
			{
				rig = true;
			}
			for (int t = 0; t < side + pos - 1; t++)
			{
				di();
			}
		}
		else //puts the corner in the back bottom right corner
		{
			bottom = true;
			for (int t = 0; t < pos; t++)
			{
				di();
			}
		}
		if (rig) //algorithm for when yellow is on the right
		{
			int color = _cube[4][2][0];
			if (color < 4) //move the top so that the corner goes into the correct position
			{
				for (int t = 0; t < color; t++)
				{
					u();
				}
			}
			r();
			d();
			ri();
			if (color < 4) //undo the setup moves to put the corner in the right position
			{
				for (int t = 0; t < color; t++)
				{
					ui();
				}
			}
		}
		else if (bottom) //algorithm for when yellow is on bottom
		{
			int color = _cube[3][2][2];
			if (color < 4) //move the top so that the corner goes into the correct position
			{
				for (int t = 0; t < color; t++)
				{
					u();
				}
			}
			r();
			d();
			d();
			ri();
			di();
			r();
			d();
			ri();
			if (color < 4) //undo the setup moves to put the corner in the right position
			{
				for (int t = 0; t < color; t++)
				{
					ui();
				}
			}
		}
		else //algorithm for when yellow is on back
		{
			int color = _cube[5][2][2];
			if (color < 4) //move the top so that the corner goes into the correct position
			{
				for (int t = 0; t < color; t++)
				{
					u();
				}
			}
			bi();
			di();
			b();
			if (color < 4) //undo the setup moves to put the corner in the right position
			{
				for (int t = 0; t < color; t++)
				{
					ui();
				}
			}
		}
	}
}

void Cube::moveTopCorners() //moves all yellow corners on the top to the bottom face
{
	for (int i = 0; i < 4; i++)
	{
		if (_cube[0][2][2] == 0 || _cube[2][0][2] == 0 || _cube[3][0][0] == 0)
		{
			while (_cube[1][2][2] == 0 || _cube[2][2][0] == 0 || _cube[5][0][0] == 0) //make sure not to push a different yellow corner back to the top
			{
				d();
			}
			ri();
			d();
			r();
		}
		u();
	}
}

void Cube::findNextTopCorner(int & s, int & p) //locates the next corner that is not in its correct spot (guaranteed to be one of the bottom four corners)
//updates pos and side in solveTopCorners() to hold the side and position of the yellow sticker
{
	for (s = 1; s < 5; s++)
	{
		if (_cube[s][2][0] == 0)
		{
			p = 1;
			return;
		}
		else if (_cube[s][2][2] == 0)
		{
			p = 2;
			return;
		}
	}
	if (_cube[5][0][0] == 0)
	{
		p = 2;
	}
	else if (_cube[5][0][2] == 0)
	{
		p = 3;
	}
	else if (_cube[5][2][2] == 0)
	{
		p = 0;
	}
	else
	{
		p = 1;
	}
}

void Cube::solveMiddleLayer()
{
	int side = -1;
	int color = -1;
	int count = 0;

beginning:
	if (side != -1)
	{
		placeMiddleEdge(color, side);
		//print();
		count++;
		side = -1;
		color = -1;
	}

	for (int i = 1; i <= 4; i++)
	{
		side = findBottomMatch(i);

		if (side != -1)
		{
			color = i;
			goto beginning;
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (_cube[i][1][0] != (i))
		{
			middleAlgorithm(i, 1);
			if(count >= 15)
			{
				solveTopCross();
				solveTopCorners();
			}

			goto beginning;
		}
		else if (_cube[i][1][2] != i)
		{
			middleAlgorithm(i, 2);

			if(count >= 10)
			{
				solveTopCross();
				solveTopCorners();
			}

			goto beginning;
		}
	}

	int done = 0;
}

int Cube::findBottomMatch(int color)
{
	for (int i = 1; i <= 4; i++)
	{
		if (_cube[i][2][1] == color)
		{
			if (i % 2 == 0)
			{
				if (_cube[5][abs(2 - i)][1] != 5)
				{
					return i;
				}
			}
			else
			{
				if (_cube[5][abs(2 - i)][i - 1] != 5)
				{
					return i;
				}
			}
		}
	}

	return -1;
}

void Cube::placeMiddleEdge(int color, int edgeSide)
{
	if (edgeSide - color == 0)
	{
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == 1)
	{
		di();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == 2)
	{
		di();
		di();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == 3)
	{
		d();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == -1)
	{
		d();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == -2)
	{
		d();
		d();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == -3)
	{
		di();
		//print();
		middleAlgorithm(color, -1);
	}
}

void Cube::middleAlgorithm(int color, int direction) //1 - L 2 - R -1 for nothing
{
	if (color == 1)
	{
		if (_cube[5][1][0] == 4 || direction == 1)
		{
			d();
			b();
			di();
			bi();
			di();
			li();
			d();
			l();
		}
		else if (_cube[5][1][0] == 2 || direction == 2)
		{
			di();
			fi();
			d();
			f();
			d();
			l();
			di();
			li();
		}
	}
	else if (color == 2)
	{
		if (_cube[5][0][1] == 1 || direction == 1)
		{
			d();
			l();
			di();
			li();
			di();
			fi();
			d();
			f();
		}
		else if (_cube[5][0][1] == 3 || direction == 2)
		{
			di();
			ri();
			d();
			r();
			d();
			f();
			di();
			fi();
		}
	}
	else if (color == 3)
	{
		if (_cube[5][1][2] == 2 || direction == 1)
		{
			d();
			f();
			di();
			fi();
			di();
			ri();
			d();
			r();
		}
		else if (_cube[5][1][2] == 4 || direction == 2)
		{
			di();
			bi();
			d();
			b();
			d();
			r();
			di();
			ri();
		}
	}
	else if (color == 4)
	{
		if (_cube[5][2][1] == 3 || direction == 1)
		{
			d();
			r();
			di();
			ri();
			di();
			bi();
			d();
			b();
		}
		else if (_cube[5][2][1] == 1 || direction == 2)
		{
			di();
			li();
			d();
			l();
			d();
			b();
			di();
			bi();
		}
	}
}

void Cube::solveBottomLayer()
{
	positionBottomCorners();
	//print();
	positionBottomEdges();
	//print();
	correctBottomCorners();
	//print();
	correctBottomEdges();
    //	print();
}

void Cube::positionBottomCorners()
{
	int dTurns[4];

	int bestNumDTurns = 0;
	int pos1 = -1;
	int pos2 = -1;

	for (int i = 0; i < 4; i++)
	{
		dTurns[i] = numCorrectCorners();

		if (dTurns[i] == 4)
		{
			pos1 = 4;
			bestNumDTurns = i;
			break;
		}
		else if (dTurns[i] < 4 && dTurns[i] > -1)
		{
			if (pos2 == -1)
			{
				pos1 = dTurns[i];
				bestNumDTurns = i;
			}
		}
		else if (dTurns[i] > 4)
		{
			int side1 = dTurns[i] % 10 + 1;
			int side2 = (int)(dTurns[i] / 10) + 1;

			//Corners are next to each other
			if (side2 == (side1 + 1) || side1 == (side2 + 1) || (side2 == 4 && side1 == 1) || (side2 == 1 && side1 == 4))
			{
				pos1 = side1;
				pos2 = side2;
				bestNumDTurns = i;
			}
			else if (pos2 == -1)
			{
				pos1 = side1;
				pos2 = side2;
				bestNumDTurns = i;
			}
		}

		d();
		//print();
	}

	for (int i = 0; i < bestNumDTurns && pos1 != 4; i++)
	{
		d();
	}


	//Finally Ready to start positioning corners with algorithm!!!!! OMG WHO KNEW A BRAIN COULD DO SO MUCH SO EASILY!!!!!

	if (pos1 == 4)
	{
		//One CRAZY lucky scenario, and is the only way to exit this nightmare :D
		return;
	}
	else if (pos2 != -1 && (pos2 == (pos1 + 1) || pos1 == (pos2 + 1) || (pos2 == 4 && pos1 == 1) || (pos2 == 1 && pos1 == 4)))
	{
		int oppFace = pos2 + 3;
		//int face = oppFace + 2;

		if (oppFace > 4)
		{
			oppFace = oppFace - 4;
		}

		swapCorners(oppFace);
		positionBottomCorners();
		return;
	}
	else if (pos2 != -1)
	{
		//Corners opp. corners correct
		int face = pos1 + 4;

		if (face > 4)
		{
			face = face - 4;
		}

		int face2 = face + 1;
		if (face2 > 4)
		{
			face2 = face2 - 4;
		}

		swapCorners(face);
		swapCorners(face2);
		swapCorners(face);
		positionBottomCorners();
		return;
	}
	else
	{
		//Only 1 correct, 3 corners wrong... If thats even posible (I'm 99% positive it isnt the way I set the cube up)?????
		//But just in case
		int face = pos1 + 2;

		if (face > 4)
		{
			face = face - 4;
		}

		swapCorners(face); //Eventually One of the previous situations above will occur :D
		positionBottomCorners();
		return;
	}

}

void Cube::swapCorners(int face)
{
	if (face == 1)
	{
		di();
		fi();
		d();
		b();
		di();
		f();
		d();
		bi();
		di();
	}
	else if (face == 2)
	{
		di();
		ri();
		d();
		l();
		di();
		r();
		d();
		li();
		di();
	}
	else if (face == 3)
	{
		di();
		bi();
		d();
		f();
		di();
		b();
		d();
		fi();
		di();
	}
	else if (face == 4)
	{
		di();
		li();
		d();
		r();
		di();
		l();
		d();
		ri();
		di();
	}
}

int Cube::numCorrectCorners()
{
	//If numCorrect ==  4 it will return 4
	//If numCorrect == 2 it will return 2nd Corner * 10 + 1st corner (i.e. 20)
	//Else if numCorrect == 1 it will return pos of corner
	//Else if 0 are correct return -1
	int cornerColors[3];
	int side1 = 0;
	int side2 = 0;

	int count = 0;

	int colorsMatch = 0; //if this equals 2 then there is a match per corner
	int position[4] = { -1, -1, -1, -1 }; //-1 means there is no match, 1 means match

	for (int i = 0; i < 4; i++)
	{
		getCorner(i, cornerColors);

		side1 = i + 1;
		side2 = i + 2;

		if (side2 == 5)
		{
			side2 = 1;
		}

		for (int j = 0; j < 3; j++)
		{
			if (cornerColors[j] == side1 || cornerColors[j] == side2)
			{
				colorsMatch++;
			}
		}

		if (colorsMatch == 2)
		{
			position[i] = 1;
			count++;
		}

		colorsMatch = 0;
	}

	int pos = 0;
	int multiplier = 1;

	if (count == 4)
	{
		return 4;
	}
	else if (count == 2 || count == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (position[i] == 1)
			{
				pos += i * multiplier;
				multiplier *= 10;
			}
		}
	}
	else
	{
		pos = -1;
	}

	return pos;
}

void Cube::getCorner(int num, int corners[])
{
	if (num == 0)
	{
		corners[0] = _cube[1][2][2];
		corners[1] = _cube[2][2][0];
		corners[2] = _cube[5][0][0];
	}
	else if (num == 1)
	{
		corners[0] = _cube[2][2][2];
		corners[1] = _cube[3][2][0];
		corners[2] = _cube[5][0][2];
	}
	else if (num == 2)
	{
		corners[0] = _cube[3][2][2];
		corners[1] = _cube[4][2][0];
		corners[2] = _cube[5][2][2];
	}
	else if (num == 3)
	{
		corners[0] = _cube[4][2][2];
		corners[1] = _cube[1][2][0];
		corners[2] = _cube[5][2][0];
	}
}

void Cube::positionBottomEdges()
{
	int pos = numEdgesInCorrectPos();

	if (pos == 0)
	{
		rotateEdges(2, true);
		positionBottomEdges();
		return;
	}
	else if (pos == 5)
	{
		return;
	}
	else
	{
		bool clockwise = pos > 0;

		int face = abs(pos) + 1;

		if (face > 4)
		{
			face = face - 4;
		}

		rotateEdges(face, clockwise);
		return;
	}
}

int Cube::numEdgesInCorrectPos()
{
	//Note this will either be 1, 0 or 4...
	//It will return 0 if none are in correct position
	//If there is one in correct position it will return the corresponding position pos or neg determining rotation
	//Note positions are determined by what side they match with, 1 - 4
	//Return 5 if all are in position

	int edges[4][2] = { { _cube[5][1][0], _cube[1][2][1] }, { _cube[5][0][1], _cube[2][2][1] }, { _cube[5][1][2], _cube[3][2][1] }, { _cube[5][2][1], _cube[4][2][1] } };

	int correctPos = -1;
	int numCorrect = 0;
	bool isOneCorrect = false;
	int positions[4];

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (edges[i - 1][j] == i)
			{
				isOneCorrect = true;
				correctPos = i - 1;
				numCorrect++;
			}

			if (edges[i - 1][j] != 5)
			{
				positions[i - 1] = edges[i - 1][j];
			}
		}
	}

	if (numCorrect == 4)
	{
		return 5;
	}

	if (isOneCorrect == false)
	{
		return 0;
	}
	else
	{
		bool clockwise = false;
		bool firstTime = true;
		int numTimesThrough = 0;
		numCorrect = 0;
		int temp;
		int temp2;

		while (numCorrect != 4)
		{
			firstTime = true;
			numCorrect = 0;
			for (int i = 0; i < 4; i++)
			{
				if (i != correctPos)
				{
					if (firstTime)
					{
						firstTime = false;
						temp = positions[i];

						int j = i - 1;

						if (j < 0)
						{
							j = 4 + j;
						}

						if (j == correctPos)
						{
							j--;
							if (j < 0)
							{
								j = 4 + j;
							}
						}

						positions[i] = positions[j];
					}
					else
					{
						temp2 = positions[i];
						positions[i] = temp;
						temp = temp2;
					}
				}

				if (positions[i] == i + 1)
				{
					numCorrect++;
				}
			}

			numTimesThrough++;
		}

		clockwise = numTimesThrough == 1;
		correctPos++;

		if (clockwise == false)
		{
			correctPos = -1 * (correctPos);
		}
	}

	return correctPos;
}

void Cube::rotateEdges(int face, bool rotClockwise)
{
	if (face == 1)
	{
		if (rotClockwise == true)
		{
			f();
			f();
			d();
			li();
			r();
			f();
			f();
			l();
			ri();
			d();
			f();
			f();
		}
		else
		{
			f();
			f();
			di();
			li();
			r();
			f();
			f();
			l();
			ri();
			di();
			f();
			f();
		}
	}
	else if (face == 2)
	{
		if (rotClockwise == true)
		{
			r();
			r();
			d();
			fi();
			b();
			r();
			r();
			f();
			bi();
			d();
			r();
			r();
		}
		else
		{
			r();
			r();
			di();
			fi();
			b();
			r();
			r();
			f();
			bi();
			di();
			r();
			r();
		}
	}
	else if (face == 3)
	{
		if (rotClockwise == true)
		{
			b();
			b();
			d();
			ri();
			l();
			b();
			b();
			r();
			li();
			d();
			b();
			b();
		}
		else
		{
			b();
			b();
			di();
			ri();
			l();
			b();
			b();
			r();
			li();
			di();
			b();
			b();
		}
	}
	else if (face == 4)
	{
		if (rotClockwise == true)
		{
			l();
			l();
			d();
			bi();
			f();
			l();
			l();
			b();
			fi();
			d();
			l();
			l();
		}
		else
		{
			l();
			l();
			di();
			bi();
			f();
			l();
			l();
			b();
			fi();
			di();
			l();
			l();
		}
	}
}

void Cube::correctBottomCorners()
{
	int result = cornerOrientation();

	while (result != 5)
	{
		twoCornerRotate(abs(findBestFace(result)), findBestFace() > 0);

		result = cornerOrientation();
	}
}

int Cube::cornerOrientation()
{
	int numCorrect = 0;
	int wrongPosition = 0;

	int corners[4] = { _cube[5][0][0], _cube[5][0][2], _cube[5][2][2], _cube[5][2][0] };

	for (int i = 0; i < 4; i++)
	{
		if (corners[i] == 5)
		{
			numCorrect++;
		}
		else
		{
			wrongPosition = i;
		}
	}

	if (numCorrect == 4)
	{
		return 5;
	}

	return wrongPosition;
}

int Cube::findBestFace(int cornerNum)
{
	int corners[4] = { _cube[5][0][0], _cube[5][0][2], _cube[5][2][2], _cube[5][2][0] };

	int corner1 = cornerNum + 1;
	int corner2 = cornerNum - 1;

	if (corner1 > 3)
	{
		corner1 = 4 - corner1;
	}

	if (corner2 < 0)
	{
		corner2 = 4 + corner2;
	}

	//First Determine which corner to go with
	int finalCorner = -1;
	int face = -1;

	if (corners[cornerNum] == corners[corner1])
	{
		finalCorner = corner1;

		face = corners[finalCorner] + 1;

		if (face > 4)
		{
			face = face - 4;
		}

		return face;
	}
	else if (corners[cornerNum] == corners[corner2])
	{
		finalCorner = corner2;

		face = corners[finalCorner] + 1;

		if (face > 4)
		{
			face = face - 4;
		}

		return face;
	}
	else if (abs(corners[cornerNum] - corners[corner1]) == 2 && corners[corner1] != 5)
	{
		finalCorner = corner1;
		face = corners[finalCorner];
		return -face;
	}
	else if (abs(corners[cornerNum] - corners[corner2]) == 2 && corners[corner2] != 5)
	{
		finalCorner = corner2;
		face = corners[cornerNum];
		return -face;
	}
	else
	{
		face = corners[cornerNum];
		return face;
	}
}

void Cube::twoCornerRotate(int face, bool goForward)
{
	if (face == 1)
	{
		if (goForward == true)
		{
			bi();
			u();
			b();
			l();
			u();
			li();
			d();
			l();
			ui();
			li();
			bi();
			ui();
			b();
			di();
		}
		else
		{
			d();
			bi();
			u();
			b();
			l();
			u();
			li();
			di();
			l();
			ui();
			li();
			bi();
			ui();
			b();
		}
	}
	else if (face == 2)
	{
		if (goForward == true)
		{
			li();
			u();
			l();
			f();
			u();
			fi();
			d();
			f();
			ui();
			fi();
			li();
			ui();
			l();
			di();
		}
		else
		{
			d();
			li();
			u();
			l();
			f();
			u();
			fi();
			di();
			f();
			ui();
			fi();
			li();
			ui();
			l();
		}
	}
	else if (face == 3)
	{
		if (goForward == true)
		{
			fi();
			u();
			f();
			r();
			u();
			ri();
			d();
			r();
			ui();
			ri();
			fi();
			ui();
			f();
			di();
		}
		else
		{
			d();
			fi();
			u();
			f();
			r();
			u();
			ri();
			di();
			r();
			ui();
			ri();
			fi();
			ui();
			f();
		}
	}
	else if (face == 4)
	{
		if (goForward == true)
		{
			ri();
			u();
			r();
			b();
			u();
			bi();
			d();
			b();
			ui();
			bi();
			ri();
			ui();
			r();
			di();
		}
		else
		{
			d();
			ri();
			u();
			r();
			b();
			u();
			bi();
			di();
			b();
			ui();
			bi();
			ri();
			ui();
			r();
		}
	}
}

void Cube::correctBottomEdges()
{
	int edges[4] = { _cube[5][1][0], _cube[5][0][1], _cube[5][1][2], _cube[5][2][1] };

	bool isTogether = false;
	bool isStart = false;
	int numWrong = 0;
	int pos1 = -1;
	int pos2 = -1;
	int j = 0;

	for (int i = 0; i < 5; i++)
	{
		j = i;

		if (i == 4)
		{
			j = 0;
		}

		if (edges[j] != 5)
		{
			numWrong++;
			if (isStart == false)
			{
				pos1 = j;
				isStart = true;
			}
			else
			{
				pos2 = j;
				isTogether = true;
			}
		}
		else
		{
			isStart = false;
		}
	}

	if (numWrong >= 4)
	{
		twoEdgeRotate(1, false);
		twoEdgeRotate(2, false);
		return;
	}
	else
	{
		if(pos2 != -1)
		{
			twoEdgeRotate(pos2 + 1, isTogether);
		}
		else
		{
			twoEdgeRotate(pos1 + 1, isTogether);
		}
		return;
	}
}

void Cube::twoEdgeRotate(int face, bool isNextTo)
{
	if (face == 1)
	{
		if (isNextTo == true)
		{
			l();
			ui();
			d();
			f();
			f();
			d();
			d();
			u();
			u();
			b();
			d();
			bi();
			u();
			u();
			d();
			d();
			f();
			f();
			di();
			u();
			li();
			di();
		}
		else
		{
			l();
			ui();
			d();
			f();
			f();
			d();
			d();
			u();
			u();
			b();
			d();
			d();
			bi();
			u();
			u();
			d();
			d();
			f();
			f();
			di();
			u();
			li();
			di();
			di();
		}
	}
	else if (face == 2)
	{
		if (isNextTo == true)
		{
			f();
			ui();
			d();
			r();
			r();
			d();
			d();
			u();
			u();
			l();
			d();
			li();
			u();
			u();
			d();
			d();
			r();
			r();
			di();
			u();
			fi();
			di();
		}
		else
		{
			f();
			ui();
			d();
			r();
			r();
			d();
			d();
			u();
			u();
			l();
			d();
			d();
			li();
			u();
			u();
			d();
			d();
			r();
			r();
			di();
			u();
			fi();
			di();
			di();
		}
	}
	else if (face == 3)
	{
		if (isNextTo == true)
		{
			r();
			ui();
			d();
			b();
			b();
			d();
			d();
			u();
			u();
			f();
			d();
			fi();
			u();
			u();
			d();
			d();
			b();
			b();
			di();
			u();
			ri();
			di();
		}
		else
		{
			r();
			ui();
			d();
			b();
			b();
			d();
			d();
			u();
			u();
			f();
			d();
			d();
			fi();
			u();
			u();
			d();
			d();
			b();
			b();
			di();
			u();
			ri();
			di();
			di();
		}
	}
	else if (face == 4)
	{
		if (isNextTo == true)
		{
			b();
			ui();
			d();
			l();
			l();
			d();
			d();
			u();
			u();
			r();
			d();
			ri();
			u();
			u();
			d();
			d();
			l();
			l();
			di();
			u();
			bi();
			di();
		}
		else
		{
			b();
			ui();
			d();
			l();
			l();
			d();
			d();
			u();
			u();
			r();
			d();
			d();
			ri();
			u();
			u();
			d();
			d();
			l();
			l();
			di();
			u();
			bi();
			di();
			di();
		}
	}
}

//-----------------------------------------------//
//----------------other Functions----------------//
//-----------------------------------------------//

void Cube::printCube()
{
	for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "    ";
				for (int k = 0; k < 3; k++)
				{
					cout << _cube[i][j][k];
				}
				cout << endl;
			}
		}cout << endl;

	for (int j = 0; j < 3; j++)
		{
			for (int i = 1; i < 5; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					cout << _cube[i][j][k];
				}
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;

	for (int i = 5; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "    ";
				for (int k = 0; k < 3; k++)
				{
					cout << _cube[i][j][k];
				}
				cout << endl;
			}
		}cout << endl;
}

// void TempCube::printCube()
// {
// 	for (int i = 0; i < 1; i++)
// 		{
// 			for (int j = 0; j < 3; j++)
// 			{
// 				cout << "    ";
// 				for (int k = 0; k < 3; k++)
// 				{
// 					cout << _tmp_cube[i][j][k];
// 				}
// 				cout << endl;
// 			}
// 		}cout << endl;

// 	for (int j = 0; j < 3; j++)
// 		{
// 			for (int i = 1; i < 5; i++)
// 			{
// 				for (int k = 0; k < 3; k++)
// 				{
// 					cout << _tmp_cube[i][j][k];
// 				}
// 				cout << " ";
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;

// 	for (int i = 5; i < 6; i++)
// 		{
// 			for (int j = 0; j < 3; j++)
// 			{
// 				cout << "    ";
// 				for (int k = 0; k < 3; k++)
// 				{
// 					cout << _tmp_cube[i][j][k];
// 				}
// 				cout << endl;
// 			}
// 		}cout << endl;
// }


void Cube::printMoves(){
	cout << moves << endl;
}

void Cube::copyCube()
{

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				_old[i][j][k] = _cube[i][j][k];

			}
		}
	}
}

string Cube::last()
{
	if (moves.size() < 3)
	{
		return "";
	}
	int s = moves.size();
	return moves.substr(s - 3, 3);
}

void Cube::removeLast()
{
	if (moves.size() < 3)
	{
		return;
	}
	int s = moves.size();
	moves = moves.substr(0, s - 3);
}

void Cube::clearMoves()
{
	moves = "";
}

void Cube::scramble()
{
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		int num = rand() % 12 + 1;
		switch (num)
		{
			case 1: r(); break;
			case 2: ri(); break;
			case 3: u(); break;
			case 4: ui(); break;
			case 5: f(); break;
			case 6: fi(); break;
			case 7: l(); break;
			case 8: li(); break;
			case 9: b(); break;
			case 10: bi(); break;
			case 11: d(); break;
			case 12: di(); break;
		}
	}
}

void/* MY NAME IS */ Cube::solveCube(){
	clearMoves();
	cout << "scrambled:" << endl;
	printCube();
	solveTopCross();
	cout << "Top Cross " << endl;
	printMoves();

	clearMoves();
	printCube();
	solveTopCorners();
	cout << "Corners " << endl;
	printMoves();

	clearMoves();
	printCube();
	solveMiddleLayer();
	cout << "Middle Layer " << endl;
	printMoves();

	clearMoves();
	printCube();
	solveBottomLayer();
	cout << "Bottom Layer " << endl;
	printMoves();
	clearMoves();
	printCube();

}

// cube questions //
	int Cube::array_to_int(int i_1, int j_1, int k_1 )
	{
		int counter = 0;
		for (int i = 0; i < 6 ;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				counter++;
			if( i == i_1 && j_1 == j && k_1 == k)
				{
					return counter;
				}
			}
		}

	}
		return 100000;
	}

	int Cube::int_to_array( int counter)
	{
		int question_array[55] = { 0,
1,
2,
10,
11,
12,
20,
21,
22,
100,
101,
102,
110,
111,
112,
120,
121,
122,
200,
201,
202,
210,
211,
212,
220,
221,
222,
300,
301,
302,
310,
311,
312,
320,
321,
322,
400,
401,
402,
410,
411,
412,
420,
421,
422,
500,
501,
502,
510,
511,
512,
520,
521,
522};
		return question_array[counter];
	}
// cube questions end //

//-----------------------------------------------//
//---------------Question/Answer-----------------//
//-----------------------------------------------//

/*void Cube::mapColor()
{

}
*/
vector< pair<int, pair<int, int> > > _ecken; //wird global als auflistung für alle zusammenhangenden Ecken benotigt

void init_Ecken(){ //einmalige initialisierung aller zusammenhangenden Felder zu Ecken
	_ecken.push_back(make_pair(0, make_pair(9, 38)));
	_ecken.push_back(make_pair(2, make_pair(29, 36)));
	_ecken.push_back(make_pair(6, make_pair(11, 18)));
	_ecken.push_back(make_pair(8, make_pair(20, 27)));
	_ecken.push_back(make_pair(45, make_pair(24, 17)));
	_ecken.push_back(make_pair(47, make_pair(33, 26)));
	_ecken.push_back(make_pair(51, make_pair(15, 44)));
	_ecken.push_back(make_pair(53, make_pair(35, 42)));
}

vector<pair<int, int>> getAdjecentEcken(int pos){ //returniert einen vector mit den angrenzenden 2 Ecken des abgefragten Felds
	vector<pair<int, int>> vec;

	for (int i=0; i<_ecken.size(); i++){
		//cout << _ecken[i].first << ", " << _ecken[i].second.first
    		// << ", " << _ecken[i].second.second << endl;//kontrollausgabe
		if(_ecken[i].first==pos) //Die anderen 2 Felder herrausfinden und zurückgeben
		{
			vec.push_back(make_pair(_ecken[i].second.first,_ecken[i].second.second));
			//cout<< "\n--" << _ecken[i].second.first << " "<<_ecken[i].second.second<< endl;
		}
		else if(_ecken[i].second.first==pos)
		{
			vec.push_back(make_pair(_ecken[i].first,_ecken[i].second.second));
			//cout<< "\n--" << _ecken[i].first << " "<<_ecken[i].second.second<< endl;
		}
		else if(_ecken[i].second.second==pos)
		{
			vec.push_back(make_pair(_ecken[i].first,_ecken[i].second.first));
			//cout<< "\n--" << _ecken[i].first << " "<<_ecken[i].second.first<< endl;
		}
	}
	return vec;
}

int Cube::getColor(int pos){//holt die eingetragene Farbe aus dem cube
	int it=0;
	for(int a=0; a<6; a++){
		for(int b=0; b<3; b++){
			for(int c=0; c<3; c++){
				if(it == pos){
						return this->_cube[a][b][c];
				}
				it++;
			}
		}
	}
}
bool isEcke(int z){
  int qPosE[]={0,2,6,8,9,11,15,17,18,20,24,26,27,29,33,35,36,38,42,44,45,47,51,53};
  int *i = find(std::begin(qPosE), std::end(qPosE), z);
  if (i != std::end(qPosE)) {
    return true;
  } else {
    return false;
  }
}

bool isKante(int z){
  int qPosK[]={1,3,5,7,10,12,14,16,19,21,23,25,28,30,32,34,27,39,41,43,46,48,50,52};
  int *i = find(std::begin(qPosK), std::end(qPosK), z);
  if (i != std::end(qPosK)) {
    return true;
  } else {
    return false;
  }
}

bool isMitte(int z){
  int qPosM[]={4,13,22,31,40,49};
  int *i = find(std::begin(qPosM), std::end(qPosM), z);
  if (i != std::end(qPosM)) {
    return true;
  } else {
    return false;
  }
}

int Cube::middleIndexOf(int pos){ //holt sich die nummer des mittelfelds der Seite auf der die gefragt Position ist

	if(pos>=0&&pos<=8)
		return 4;
	if(pos>8&&pos<=17)
		return 13;
	if(pos>18&&pos<=26)
		return 22;
	if(pos>27&&pos<=35)
		return 31;
	if(pos>=36&&pos<=44)
		return 40;
	if(pos>=45&&pos<=53)
		return 49;
}
multimap <int,int> _kanten; //globale kanten

void Cube::init_Kanten(){ //multimap aller Kanten und deren Felder anlegen
	_kanten.insert( pair <int,int> (1,37));
	_kanten.insert( pair <int,int> (3,10));
	_kanten.insert( pair <int,int> (5,28));
	_kanten.insert( pair <int,int> (7,19));
	_kanten.insert( pair <int,int> (10,3));
	_kanten.insert( pair <int,int> (12,41));
	_kanten.insert( pair <int,int> (14,21));
	_kanten.insert( pair <int,int> (16,48));
	_kanten.insert( pair <int,int> (19,7));
	_kanten.insert( pair <int,int> (21,14));
	_kanten.insert( pair <int,int> (23,30));
	_kanten.insert( pair <int,int> (25,46));
	_kanten.insert( pair <int,int> (28,5));
	_kanten.insert( pair <int,int> (30,23));
	_kanten.insert( pair <int,int> (32,39));
	_kanten.insert( pair <int,int> (34,50));
	_kanten.insert( pair <int,int> (37,1));
	_kanten.insert( pair <int,int> (39,32));
	_kanten.insert( pair <int,int> (41,12));
	_kanten.insert( pair <int,int> (43,52));
	_kanten.insert( pair <int,int> (46,25));
	_kanten.insert( pair <int,int> (48,16));
	_kanten.insert( pair <int,int> (50,34));
	_kanten.insert( pair <int,int> (52,43));
}

int Cube::getAdjecentKante(int pos){ //angrenzende Kante aus der Liste finden
  return _kanten.find(pos)->second;
}

string randomizeFeedback(string s){ //randomisiert den von der generateMastermindAnswer Methode erstellten Feedbackstring
	string randFeedback, feedback=s;
  int num =0;
  list<int> my_list;
  list<int>::iterator it;

  for(int i=0;i<feedback.length();i++){
    randFeedback.append("0");
  }

  for(int i=0;i<feedback.length();i++){

  while(find(my_list.begin(), my_list.end(), num)!=my_list.end()){
    num = rand() % feedback.length();
    //cout<<num;
  }
    my_list.push_back(num);
    randFeedback[i]=feedback[num];
  }
  //cout<< "\n fkt: "<<randFeedback;

  return randFeedback;
}


//bis hier Matthias 7.2.20

string Cube::splitQuestion(string s, int n) //by Isabella Reithner
{
	cout<< "--Entering splitQ"<<endl;
	int pos = 0; //Position
	char color = ' '; //Farbe
	int question[n]; //Farbe aus der Frage
	int groundTruth[n]; //Farbe im verdrehten (übergebenen) Würfel
	string tmp; //temporärer Speichererort des gespaltenen Strings
	int cnt = 0; //counter
	int it = 0; //Zähler für Iterationen (ebenfalls ein Counter)
	//von Matthias Anfang
	int white=0; //Zähler für Richte Farbe am Falschen Platz
	int black=0; //Zähler Richtige Farbe richtiger Platz
	string feedback;
	int qPos[n], qCol[n], gtPos[n], gtCol[n];

	init_Kanten();//wir jedes mal beim Feedback request neu initialisiert->Performance?
	init_Ecken();
	int h=0;//ungut,, listen bzw vektoren wären besser

	for(int j=0; j<n*3; j+=3){ //Spalten der Frage in Position und Farbe
		it = 0;
		int pos1=((int)(s[j])-'0');
		int pos2=(int)(s[j+1])-'0';
		pos = pos1*10+pos2;

		color = s[j+2];
		int farbe = (int)(color)-48;//ASCII-Zahl um 48 verschieben
		qPos[h]=pos;
		qCol[h]=farbe;

//Durchgehen des übergebenen Würfels
		for(int a=0; a<6; a++){ //Seite
			for(int b=0; b<3; b++){ //Zeile
				for(int c=0; c<3; c++){ //Spalten
					if(it == pos){ //Wenn die Position befunden wurde, Farbe in reference schreiben
						gtPos[h]=pos;
						gtCol[h]=this->_cube[a][b][c];
						cout<<"it: " << h << ". gt an Position: "<< gtPos[h]<<" hat Farbe "<< gtCol[h] << ". Zu Farbe in Question: "<<qCol[h] <<endl;
					}
					it++;
				}
			}
		}
		cnt++;
		h++;
	}

	return	this->generateMastermindAnswer(&qPos[0],&qCol[0],n);

}

string Cube::generateMastermindAnswer(int* qPos, int *qCol, int n ){
	string randFeedback;
	int num =0;
	list<int> my_list;
	list<int>::iterator it;
	bool b;

	for(int i=0;i<n;i++){
		//cout<<"\nqPos["<<i<<"] "<< qPos[i];

		if(isMitte(qPos[i]))
		{//cout<<" m ";
			if(qCol[i]==getColor(middleIndexOf(qCol[i])))//Wenn die Farbe aus der Frage vom aktuellen Mittelfeld gleich der Farbe an der seleben Stelle im scrambeld Cube
			{
				//cout<<"b";
				feedback.append("b");
			}else{
				//cout << "w";
				feedback.append("x");
			}
		}

		if(isKante(qPos[i]))
		{
			//cout<<qPosK[i] << " " << middleIndexOf(qPosK[i]) << " " <<getColor(middleIndexOf(qPosK[i]))<<endl;
			if(qCol[i]!=getColor(middleIndexOf(qPos[i]))){
				//wenn die frabe der Kante nicht gleich der Farbe des mittelfelds der gleichen seite ist
				//cout<<"x";
				feedback.append("x");
			}else{//wenn die farbe der Kante gleich der Farbe des mittlfeldes der gleichen seite ist
				//wenn farbe des um die Ecke angrenzenden Felds gleich wie die Mitte dieser Seite ist
				if(getAdjecentKante(qPos[i])==getColor(middleIndexOf(getAdjecentKante(qPos[i])))){
				//cout<<"b";
					feedback.append("b");
				}
				else
				{
					//cout<<"w";
					feedback.append("w");
				}
			}
		}

		if(isEcke(qPos[i]))
		{
			//cout<<" e ";
			int a,b;
			vector<pair<int,int>> adjEcken;
			adjEcken=getAdjecentEcken(qPos[i]);
			a=adjEcken[0].first;
			b=adjEcken[0].second;
			//cout<< "--a: "<< a << " b: "<<b<<endl;
			bool s1,s2,s3;

			if(qCol[i]==getColor(middleIndexOf(qPos[i]))) s1=true; else s1=false;
				//cout<<s1;
			if(getColor(a)==getColor(middleIndexOf(a))) s2=true; else s2=false;
				//cout<<s2;
			if(getColor(b)==getColor(middleIndexOf(b))) s3=true; else s3=false;
				//cout<<s3;

			if(s1==true&&s2==true&&s3==true){
					//cout<< ".b";
				feedback.append("b");
			}
			else

			/*if((s1==true&&s2==false&&s3==false)||(s1==false&&s2==true&&s3==false)||(s1==false&&s2==false&&s3==true))
				{cout<< ".w"; feedback.append(".w");}*/

			if(s1==false&&s2==false&&s3==false){
				//cout<< ".x";
				feedback.append("x");
			}else{
				//cout<< ".w";
				feedback.append("w");
			}
		}
	}
	cout <<"\nFeedback: "<< feedback<<endl;
		//randomize feedbackstring
	string temp=randomizeFeedback(feedback);
	cout<<"Randomisiertes Feedback: "<<temp <<endl;
	return temp;
}


//-----------------------------------------------//
//---------------- Switch Edges -----------------//
//-----------------------------------------------//

void Cube::switchEdges(int top, bool direction){ //destroys corners!!!!
	//direction - 0 left; 1 right

	if(top==0) //orientiere Cube mit benötigter Fläche oben
		; //nothing;
	else if(top==1){
		globalRotationR();
		globalRotationU();
	}
	else if(top==2){
		globalRotationU();
	}
	else if(top==3){
		globalRotationL();
		globalRotationU();
	}
	else if(top==4){
		globalRotationR();
		globalRotationR();
		globalRotationU();
	}
	else if(top==5){
		globalRotationU();
		globalRotationU();
	}

	if(direction==0){ // left
		r();
		u();
		ri();
		u();
		r();
		u();
		u();
		ri();
		u();
	}
	else if(direction==1){ //right
		l();
		ui();
		li();
		ui();
		l();
		ui();
		ui();
		li();
		ui();
	}

	if(top==0) //Bringe Cube in globale Ausgangslage zurück
		; //nothing;
	else if(top==1){
		globalRotationD();
		globalRotationL();
	}
	else if(top==2){
		globalRotationD();
	}
	else if(top==3){
		globalRotationD();
		globalRotationR();
	}
	else if(top==4){
		globalRotationD();
		globalRotationL();
		globalRotationL();
	}
	else if(top==5){
		globalRotationU();
		globalRotationU();
	}
}

bool Cube::isCorrectEdge(int i, int j, int k){
	//return 0 wenn edge an richtiger position
	//return 1 wenn edge an falscher position

	if(_cube[i][j][k] == _cube[i][1][1]){
		if(j==0){
			if(_cube[i+4][0][1] == _cube[i+4][1][1])
				return 0;
			else
				return 1;
		}
		else if(j==1){
			if(i==0){
				if(_cube[i+1][0][1] == _cube[i+1][1][1])
					return 0;
				else
					return 1;
			}
			else{ //i==2
				if(_cube[i+3][0][1] == _cube[i+3][1][1])
					return 0;
				else
					return 1;
			}
		}
		else{ // j==2
			if(_cube[i+2][0][1] == _cube[i+2][1][1])
				return 0;
			else
				return 1;
		}
	}
	else
		return 1;
}

void Cube::findSwitchableEdges(){
	int cnt = 0;
	int positions[4] = {-1};
	int pos = 0;

	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(isKante(cnt) == 1 && _cube[i][j][k]!=-1 ){
					cout << "got it at " << cnt << endl;
					positions[pos] = cnt;
					pos++;
					//Do the moves
				}
				cnt ++;
			}
		}
	}
}


int Cube::findTopEdgePos(int side, int pos){
	int s, p;
	for (s = 1; s < 6; s++)
	{
		if (_cube[s][0][1] == 0)
		{
			p = 1;
			return p;
			break;
		}
		else if (_cube[s][1][2] == 0)
		{
			p = 2;
			return p;
			break;
		}
		else if (_cube[s][2][1] == 0)
		{
			p = 3;
			return p;
			break;
		}
		else if (_cube[s][1][0] == 0)
		{
			p = 4;
			return p;
			break;
		}
	}
}
int Cube::findTopEdgeSide(int side, int pos){
	int s, p;
	for (s = 1; s < 6; s++)
	{
		if (_cube[s][0][1] == 0)
		{
			p = 1;
			return s;
			break;
		}
		else if (_cube[s][1][2] == 0)
		{
			p = 2;
			return s;
			break;
		}
		else if (_cube[s][2][1] == 0)
		{
			p = 3;
			return s;
			break;
		}
		else if (_cube[s][1][0] == 0)
		{
			p = 4;
			return s;
			break;
		}
	}
}

void Cube::moveToTopCross(){
	moveTopEdges();

	for (int i = 1; i < 5; i++)
	{
		int side = 0; //side that the yellow sticker is on
		int pos = 0; //position (1-4) of the yellow sticker
		pos = findTopEdgePos(side, pos);
		side = findTopEdgeSide(side, pos);
		//cout << side << " " << pos << endl;
		int numTurns = 0; //keeps track of how many times we turn the cube to put pieces on the bottom layer so we can undo the turns
		if (side == 1)
		{
			while (_cube[5][1][0] == 0)
			{
				d();
			}
			while (_cube[0][1][0] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				l();
				l();
			}
			else if (pos == 2)
			{
				l();
			}
			else if (pos == 4)
			{
				li();
			}
		}
		else if (side == 2)
		{
			while (_cube[5][0][1] == 0)
			{
				d();
			}
			while (_cube[0][2][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				f();
				f();
			}
			else if (pos == 2)
			{
				f();
			}
			else if (pos == 4)
			{
				fi();
			}
			di();
		}
		else if (side == 3)
		{
			while (_cube[5][1][2] == 0)
			{
				d();
			}
			while (_cube[0][1][2] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				r();
				r();
			}
			else if (pos == 2)
			{
				r();
			}
			else if (pos == 4)
			{
				ri();
			}
			d();
			d();
		}
		else if (side == 4)
		{
			while (_cube[5][2][1] == 0)
			{
				d();
			}
			while (_cube[0][0][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				b();
				b();
			}
			else if (pos == 2)
			{
				b();
			}
			else if (pos == 4)
			{
				bi();
			}
			d();
		}
		else if (side == 5)
		{
			for (int j = 0; j < 4 - pos; j++)
			{
				d();
			}
		}

		for (int j = 0; j < numTurns; j++)
		{
			ui();
		}

		if (side == 5) //algorithm for when the sticker is on the bottom
		{
			int color = i;
			for (int a = 1; a < color; a++) //set-up so that the edge goes into the right spot
			{
				u();
			}
			l();
			l();
			for (int a = 1; a < color; a++) //undo set-up
			{
				ui();
			}
		}
		else //algorithm for when th esticker is not on the bottom
		{
			int color = i;
			if (color < 4) //set-up so that the sticker goes into the right spot
			{
				for (int a = 1; a < color + 1; a++)
				{
					u();
				}
			}
			l();
			bi();
			li();
			if (color < 4) //undo set-up
			{
				for (int a = 1; a < color + 1; a++)
				{
					ui();
				}
			}
		}
	}
}

void Cube::switchEdgesTopCross(){
	/*
		Überall wo "MASTERMIND" steht muss die Bedingung des
		Masterminds eingesetzt werden
	*/
	int cnt = 0;
	while(cnt < 12){
		if(getColor(10) == getColor(13)){ // <- MASTERMIND
			cout << "correct color 1"<< endl;
			globalRotationL();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40); // <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationR();
			//printCube();
			break;
		}
		else if(getColor(19) == getColor(22)){ // <- MASTERMIND
			cout << "correct color 2"<< endl;
			globalRotationR();
			globalRotationR();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationL();
			globalRotationL();
			//printCube();
			break;
		}
		else if(getColor(28) == getColor(31)){ // <- MASTERMIND
			cout << "correct color 3"<< endl;
			globalRotationR();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationL();
			printCube();
			break;
		}
		else if(getColor(37) == getColor(40)){ // <- MASTERMIND
			cout << "correct color 4"<< endl;
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			printCube();
			break;
		}
		switchEdges(0, 0);
		u();
		cnt ++;
		//cout << "TRY " << cnt << endl;
		//printCube();
	}
}


//-----------------------------------------------//
//------------------Sonstiges--------------------//
//-----------------------------------------------//

void Cube::writeCube(int position, int color){
	int cnt = 0;
	for(int a=0; a<6; a++){ //Seite
		for(int b=0; b<3; b++){ //Zeile
			for(int c=0; c<3; c++){ //Spalten
				if(cnt == position){
					_cube[a][b][c] = color;
				}
				cnt++;
				//else break;
			}
		}
	}
}
