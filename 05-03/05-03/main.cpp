//
//  main.cpp
//  HalloWelt
//
//  Created by Jannis Seemann on 06.06.17.
//  Copyright © 2017 Jannis Seemann. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/*
void doSomething(string word) {
    cout << word.length() << ": " << word << endl;
}
*/

void printMulti(string word, int n) {
    for (int i = 0; i < n; i++) {
        cout << word << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    printMulti("Hallo Welt", 4);
    
    return 0;
}
