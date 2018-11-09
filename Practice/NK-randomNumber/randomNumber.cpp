#include <iostream>

using namespace std;

int main() {
    int inputNum, num;
    while (cin >> inputNum) {
        int numArray[1001] = { 0 };
        while (inputNum--) {
            cin >> num;
            numArray[num] = 1;
        }
        for (int i = 0; i < 1001; i++)
            if (numArray[i])
                cout << i << endl;
    }
    return 0;
}
