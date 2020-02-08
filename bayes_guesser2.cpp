#include <iostream>
#include<utility>
#include<map>
#include<iterator>
#include<tuple>
#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;
//2.Version: hab probiert das pos[]-array durch einen vektor zu ersetzten


//farben fix und positionen raten
//3 stelligen() mit 9 stelligen(t)(hat 3 mal die farbe 4) array vergleichen. suchen wo diese 3 4er sind
void showlist(list <vector<int>> g)
{
    list <vector<int>> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it){
        cout<<*it;
      }
}

int main(){
  list<vector<int>> positionen, wert; //positionen ist pos-array, wert ist der counter
  vector<int> w;
  srand(time(NULL));

  int n=3; //unser normales n
  int M = 1000; //anzahl an Guesses
  int t[] = {4,4,4,1,0,0,2,2,2}; //Positionen die wir erraten wollen (1 seite)
  vector<int> pos;
  int counter=0;//anzahl w und s
  //float cutoff= n*0.9;
  int cutoff=2;//ausbeserm
  //z=(int)cutoff;//funktioniert??

  for(int z=0;z<1000;z++){
    counter = 0;
    for(int i=0;i<n;i++){//hier wird der index des arrays t erstellt, anden die abzufragende Farbe 4 ist
      pos.push_back(rand() % 8);
    }

    //pos = 2,4,6
    std::vector<vector<int>> p;
    for(auto i=0;i<pos.size();i++){
    //for(int i=0;i<n;i++){
      if(t[pos[i]]==4){
        counter++;
      }
      p.push_back(pos[i]);
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
