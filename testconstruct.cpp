using namespace std;
#include <iostream>

class XClass 
{
    public:
    int a;
    XClass(int b):a(b) 
    {;}
};

int main() 
{
    XClass xObj(20);
    xObj.a = 100;
    cout<< xObj.a; 
    cout << endl;
    return 0; 
}
