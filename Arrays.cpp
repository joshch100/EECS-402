using namespace std;
#include <iostream>
#include <iomanip> 


int main()
{   
    int i0, i1, i2;
    int sum;
    cout << "Enter int #1: "; 
    cin >> i0;
    cout << "Enter int #2: "; 
    cin >> i1;
    cout << "Enter int #3: ";
    cin >> i2;
    cout.setf(ios::right);
    cout << " " << setw(4) << i0 << endl; 
    cout << "+ " << setw(4) << i1 << endl; 
    cout << "+ " << setw(4) << i2 << endl; 
    cout << " ----" << endl;
    sum = i0 + i1 + i2;
    cout << " " << setw(4) << sum << endl;  
}
