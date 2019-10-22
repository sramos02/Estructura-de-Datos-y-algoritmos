//https://www.aceptaelreto.com/problem/statement.php?id=156
#include <iostream>
using namespace std;

bool resuelveCaso() {
	int v[2]; //Vamos comparando todo el rato los ultimos dos que nos entran
	int abs, aux;
	int i = 0, ret = 0;
	bool fin = false;

	cin >> v[0]; i++; //Mete el primero y prepara el segundo
	if (v[0] < 0) return true; //Ha llegado al final del programa

	while (!fin) {
		cin >> v[i];
		if (v[i] >= 0) {
			if((aux = (i - 1)) < 0) aux = -aux; //Se supone que -1%2 = 1 pero no lo procesa
			abs = (v[aux] - v[i]);  
			if (abs < 0) abs *= -1;
			ret += abs;
		}
		else {
			cout << ret << endl;
			fin = true;
		}
		i = ((i + 1) % 2);
	}

	return false;
}

int main() {
	bool fin = false;
	while (!fin) {
		fin = resuelveCaso();
	}
	return 0;
}
