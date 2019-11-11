//https://www.aceptaelreto.com/problem/statement.php?id=140
#include <iostream>
using namespace std;

int solveCase(int n) {
	int acum = 0;
	
	if (n < 10) {
		cout << n;
		return n;
	}
	acum = solveCase(n / 10) + n%10;
	cout << " + " << n%10;

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
