
using namespace std;
#include <iostream>
#include <string>
#include <cmath>

class Stats {
    private:
        int size;
        int *arr;

    public:

        Stats(int sizeIn) {
            size = sizeIn;
            int *arr = new int[size];
        }

        void setVal(int index, int num) {
            arr[index] = num;
        }

        int max() {
            int maxElt = arr[0];

            for(int i = 0; i < size; ++i) {
                if(arr[0] > maxElt) {
                    maxElt = arr[0];
                }
            }

            return maxElt;
        }

        void printArr() {
            for(int i = 0; i < size; ++i) {
                cout << arr[i] << endl;
            }
        }

};



int main() {

  Stats myStats(3);

  // set array to 3, 2, 1
  myStats.setVal(0, 3);
  myStats.setVal(1, 2);
  myStats.setVal(2, 1);

  cout << "Find max of array. Expect 3" << endl;
  cout << "Array max: " << myStats.max() << endl;

  // set array to 1, 2, 3
  myStats.setVal(0, 1);
  myStats.setVal(1, 2);
  myStats.setVal(2, 3);

  cout << "Find max of array. Expect 3" << endl;
  cout << "Array max: " << myStats.max() << endl;

  return 0;
}

