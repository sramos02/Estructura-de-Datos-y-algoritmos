#include <iostream>
#include <vector>
using namespace std;


int buscaMinimo(const vector<int> datos, int ini, int fin) {
		
	if (datos.size() == 2) {
		if(datos[ini] < datos[fin - 1]) return datos[ini];
		else return datos[fin - 1];
	}

	if (ini + 1 == fin) return datos[ini];

	int m = (ini + (fin - 1)) / 2;
	if (m > 0 && m < datos.size()) {
		if (datos[m - 1] > datos[m] && datos[m + 1] < datos[m]) return buscaMinimo(datos, m + 1, fin);
		else if (datos[m - 1] < datos[m] && datos[m + 1] < datos[m]) return buscaMinimo(datos,ini, m);
		else return datos[m];
	}
	return datos[m];
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;

	vector<int> datos;

	for (int i = 0; i < n; i++) {
		int aux;
		cin >> aux;
		datos.push_back(aux);
	}

	cout << buscaMinimo(datos, 0, datos.size()) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
