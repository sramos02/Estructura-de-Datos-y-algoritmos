//https://www.aceptaelreto.com/problem/statement.php?id=114
//ULTIMO DIGITO DEL FACTORIAL

#include <iostream>
#include <stdio.h>
using namespace std;


void resuelveCaso() {
	int n;
	cin >> n;

	if (n == 0) cout << 1 << endl;
	else if (n == 3) cout << 6 << endl;
	else if (n < 5) cout << n << endl;
	else cout << 0 << endl;
}


int main() {
	unsigned int numCasos;
	cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) { 
		resuelveCaso(); 
	}

	return 0;
}
