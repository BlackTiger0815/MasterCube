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
void showlist(list <vector<int>> g)
{
    list <vector<int>> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it){
        cout << *it<<" ";
    cout << '\n';}
}

int main(){
  list<vector<int>> positionen, wert; //positionen ist pos-array, wert ist der counter
  vector<int> w;
  srand(time(NULL));

  int n=3; //unser normales n
  int M = 1000; //anzahl an Guesses
  int t[] = {4,4,4,1,0,0,2,2,2}; //Positionen die wir erraten wollen (1 seite)
  int pos[3];
  int counter=0;//anzahl w und s
  //float cutoff= n*0.9;
  int cutoff=2;//ausbeserm
  //z=(int)cutoff;//funktioniert??

  for(int z=0;z<1000;z++){
    counter = 0;
    for(int i=0;i<3;i++){//hier wird der index des arrays t erstellt, anden die abzufragende Farbe 4 ist
      pos[i] = rand() % 8;
    }
    //pos = 2,4,6

    vector<int> p;
    for(int i=0;i<n;i++){
      if(t[pos[i]]==4){
        counter++;
      }
      int x =pos[i];
      p.push_back(x);
    }

  /*  if(counter>=cutoff){//gute guesses behalten
      positionen.push_back(p);
      wert.push_back(counter);
    }*/
  }
  cout << "positionen: ";
  showlist(positionen);
  cout<< "counter: ";
  showlist(wert);

  //was ist die Zahl die an allen Stellen am häufigsten vorkommt
  /*list <vector<int>> :: iterator it;
  for(it = g.begin(); it != g.end(); ++it)
      for(int i = *it)// durchgehen, die einzelen positionen
{


}*/
return 0;
}
