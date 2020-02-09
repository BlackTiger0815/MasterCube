/*noch zu tun:
 + eine Position darf im bestGuess nicht doppelt vorkommen
 + counter soll anzahl an 1 und 2 aus Feedbackstring zählen. = wert
 + nach verschiedenen Farben gleichzeitig suchen können
 + falls n>"gesuchter Farben", überlegen was mit überschissigen Felder zu tun ist.
+ random zahl zwischen 0 und t.length erstellen*/

#include <iostream>
#include<utility>
#include<map>
#include<iterator>
#include<tuple>
#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;
//erste Version

//farben fix und positionen raten
//3 stelligen() mit 9 stelligen(t)(hat 3 mal die farbe 4) array vergleichen. suchen wo diese 3 4er sind
void showlist2(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it){
        cout << *it;
    cout << " ";}
}

void showlist1(list <vector<int>> g)
{int z=0;
list <vector<int>> :: iterator it;

for(it = g.begin(); it != g.end(); ++it){
    if(z%8==0)cout<< "\n";

		vector<int> actual_vector = *it;
		for (int i = 0; i < actual_vector.size(); i++) {
		std::cout << actual_vector.at(i) << " ";
    z++;
		}
	cout << "  ";

}

}

int main(){
  list<vector<int>> positionen;
  list<int> wert; //positionen ist pos-array, wert ist der counter
  vector<int> w;
  srand(time(NULL));

  int n=4; //unser normales n
  int M = 1000; //anzahl an Guesses
  int t[] = {4,4,4,4,0,0,2,2,2}; //Positionen die wir erraten wollen (1 seite)
  int pos[n];
  int counter=0;//anzahl w und s
  //float cutoff= n*0.9;
  int cutoff=2;//ausbeserm
  //z=(int)cutoff;//funktioniert??

  for(int z=0;z<1000;z++){//++++++++++++++BEGIN OF FOR
    counter = 0;
    for(int i=0;i<n;i++){//hier wird der index des arrays t erstellt, anden die abzufragende Farbe 4 ist
      pos[i] = rand() % 8;//sollen. 0-8zahler
      cout<<"posi "<<pos[i];
    }
    cout<<"\n";
    //pos = 2,4,6

    vector<int> p;
    for(int i=0;i<n;i++){
      if(t[pos[i]]==4){
        counter++;
      }
      int x =pos[i];
      //cout<<"x"<<x;
      p.push_back(x);
      /*for (int i = 0; i < p.size(); i++){
        cout <<"p[i]"<< p[i];
      }*/
      cout<<"\n";
    }
    //for (int i = 0; i < p.size(); i++)
      //  cout << p[i] << " ";

    if(counter>=cutoff){//gute guesses behalten
      positionen.push_back(p);
      wert.push_back(counter);
    }
  }//+++++++++++++++++++++END OF FOR. bis hier wird gefüllt

  cout<<"positionen.size():"<<positionen.size()<<" "<<endl;
  cout << "positionen: "<<endl;
  showlist1(positionen);
  //cout<< "counter: "<<endl;
  //showlist2(wert);
  vector<int> bestGuess;
  int max=0,haeufigste=0;

  for(int u=0;u<n;u++){//++++++++++++++++++BEGIN OF FOR
    cout<<"\n--u = "<<u;
    list <vector<int>> :: iterator iterator;
    vector<int> spalte;
    for(iterator = positionen.begin(); iterator != positionen.end(); ++iterator){
    	vector<int> actual_vector = *iterator;
      //cout<< "\nactual_vector " << actual_vector.at(l);
      spalte.push_back(actual_vector.at(u));
    }

    int i,last,temp;

    sort(spalte.begin(),spalte.end());//vector sortieren, damit einfacher evaluiert werden kann
    cout<<"\n--spalte.size(): "<<spalte.size();
    for(i=0;i<spalte.size();i++){
      int zahl=spalte.at(i);

      if(last!=zahl){
        int count = std::count(spalte.begin(),spalte.end(),spalte.at(i));
        cout<<"\nZahl "<<spalte.at(i)<<" kommt " << count << " mal vor";
          if(count>max){
            max=count;
            haeufigste=spalte.at(i);
          }
          count=0;//counter für die nächste  zählung zurücksetzten
      }
      last=zahl;//sicherung, damit kein wert doppelt gezählt wird
    }
    //cout<<"check";
    spalte.clear();//spaltenvector leeren, da ansonst alle anderen spalten dazugesepcihert werden;
    cout<< "\nhaeufigste Zahl: "<<haeufigste<<endl;
    bestGuess.push_back(haeufigste);
    //cout<<"c"<<endl;
  }//+++++++++++++++++++++++++++++END OF FOR


  cout <<"bestGuess ";
  for (int i = 0; i < bestGuess.size(); i++)
          cout << bestGuess[i] << " ";

  /*list <vector<int>> :: iterator it;
  for(it = g.begin(); it != g.end(); ++it)
      for(int i = *it)// durchgehen, die einzelen positionen
{


}*/

return 0;
}
