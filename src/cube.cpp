#include "cube.h"
#include <stdio.h>//für memcpy
#include <cstring>//für memcpy
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

//-----------------------------------------------//
//----------------other Functions----------------//
//-----------------------------------------------//

void Cube::printCube()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << _cube[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}

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

//-----------------------------------------------//
//---------------Question/Answer-----------------//
//-----------------------------------------------//

/*void Cube::mapColor()
{

}
*/
void Cube::splitQuestion(string s, int n) //by Isabella Reithner
{
	int pos = 0; //Position
	char color = ' '; //Farbe
	int question[n]; //Farbe aus der Frage
	int reference[n]; //Farbe im verdrehten (übergebenen) Würfel
	string tmp; //temporärer Speichererort des gespaltenen Strings
	int cnt = 0; //counter
	int it = 0; //Zähler für Iterationen (ebenfalls ein Counter)
	//von Matthias Anfang
	int rffp=0; //Zähler für Richte Farbe am Falschen Platz
	int rfrp=0; //Zähler Richtige Farbe richtiger Platz
	string feedback;
	int tempReference[n];//für die Farbvergleiche



	for(int j=0; j<n*3; j+=3){ //Spalten der Frage in Position und Farbe
		it = 0;
		int pos1=((int)(s[j])-'0');
		int pos2=(int)(s[j+1])-'0';
		pos = pos1*10+pos2;
		//pos = ((int)(s[j])-'0')*10+((int)(s[j+1])-'0');

		//cout << pos << ':'<< pos1 << ':' << pos2<< ':'<< endl;
		color = s[j+2];
		question[cnt] = (int)(color)-48; //ASCII-Zahl um 48 verschieben

//Durchgehen des übergebenen Würfels
		for(int a=0; a<6; a++){ //Seite
			for(int b=0; b<3; b++){ //Zeile
				for(int c=0; c<3; c++){ //Spalten
					if(it == pos){ //Wenn die Position befunden wurde, Farbe in reference schreiben
						reference[cnt] = this->_cube[a][b][c];
						//cout<<"ref "<< reference[cnt]<< endl;
					}
					it++;
				}
			}
		}
		cnt++;
	}
	for(int k=0; k<n; k++){
		cout << reference[k] << " " << question[k] << endl;
		//this->generateMastermindAnswer(question,reference,n);
	}
	this->generateMastermindAnswer(&question[0],&reference[0],n);//reference sollte ground truth heißen

}


void Cube::generateMastermindAnswer(int *questions, int *reference, int n){

	int rffp=0; //Zähler für Richte Farbe am Falschen Platz
	int rfrp=0; //Zähler Richtige Farbe richtiger Platz
	string feedback;
	int tempReference[n];
	int tempCode[n];

for(int i=0;i<n;i++){ //memcpy hat manchmal nicht funktioniert
	tempReference[i]=reference[i];
}
	//memcpy(tempReference,reference,n);//Eventuell ein Laufzeitfehler wegen N!!!!
	//schwarz ist 1, weiß ist 0 und nix ist 2
	for(int k=0; k<n; k++){
		cout<< "que u ref u tempReference: "<< questions[k]<<" "<<reference[k]<<" "<<tempReference[k]<<endl;
		if(reference[k]==questions[k]&&tempReference[k]!=9){//Farbe und Position richtig
			rfrp++;
			feedback.append("1");
			tempReference[k]=9;//Diese Position wird 9 gesetzt, damit das Programm weiß, dass hier schon mal überprüft wurde, und keine Farben doppelt zählt
		}
	}
	cout<<"rfrp "<<rfrp<< std::endl;

	int k=0;
	for(int j=0;j<n;j++){
		if(tempReference[j]!=9)
		{
			//cout<< "que u ref u tempReference: "<< questions[j]<<" "<<reference[k]<<" "<<tempReference[j]<<endl;
			if(reference[k]==questions[j]&&tempReference[j]!=9){
				rffp++;
				tempReference[j]=9;
				feedback.append("0");
			}
		}
		k++;
	}
	cout<<"rffp " << rffp<< std::endl;

	//nur Richtig , wenn WENN n ANZAHL DER WERTE IST!!!
	for(int i=rffp+rfrp;i<n;i++){//Hier wird mit x aufgefüllt (falls es etwas zum auffüllen gibt)
		feedback.append("2");
	}
	std::cout <<"feedback: "<< feedback << std::endl; //Von Matthias hinzugefügt
}
