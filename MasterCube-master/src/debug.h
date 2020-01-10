#include <iostream>
using namespace std;

class debug{
private:
    bool debug_mode;

public:
    template <typename T>
	void printf(const T& x)
    {
        if (debug_mode) {
            cout << x << endl;
        }
	}

    void setdebug(bool a)
        {
            debug_mode = a;
        }
    

};


/*
#Debugger.setdebug(0);
#Debugger.printf("hello world show  not");
#Debugger.setdebug(1);
#Debugger.printf("hello world show");
*/