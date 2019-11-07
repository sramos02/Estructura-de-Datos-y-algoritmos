//https://www.aceptaelreto.com/problem/statement.php?id=140
#include <iostream>
using namespace std;

int resuelveCaso(int n, int aux) {
	int acum = 0;

	if (n < 10) {
		cout << n % 10;
		acum += n%10;
	}
	else {
		acum = resuelveCaso(n / 10, aux + n % 10) + n % 10;
		cout << " + " << n % 10;
	}

	return acum;
}

int main() {
	
	int n;
	cin >> n;

	while (n != -1) {
		int aux = resuelveCaso(n, 0);
		cout << " = "<< aux << endl;
		cin >> n;
	}

	return 0;
}
