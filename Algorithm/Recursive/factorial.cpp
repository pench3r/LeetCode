#include <iostream>

using namespace std;

static int factorial(int number);

int main(int argc, char *argv[]) {
	cout << factorial(5) << endl;
	return 0;
}

static int factorial(int number) {
	if (number == 1) return 1;	
	return number * factorial(number-1);
}
