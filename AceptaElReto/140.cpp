//https://www.aceptaelreto.com/problem/statement.php?id=140
#include <iostream>
using namespace std;

int solveCase(int n) {
	int acum = 0;
	int digit = n%10;
	
	if (n < 10) {
		cout << digit;
		acum += digit;
	}
	else {
		acum = solveCase(n / 10) + digit;
		cout << " + " << digit;
	}

	return acum;
}

int main() {
	int n;
	cin >> n;

	while (n != -1) {
		int aux = solveCase(n);
		cout << " = "<< aux << endl;
		cin >> n;
	}

	return 0;
}
