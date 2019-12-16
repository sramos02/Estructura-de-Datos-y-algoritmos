#include <iostream>
#include <vector>
using namespace std;


int curvaConcava(vector<int> datos, int ini, int fin) {
	if (ini + 1 == fin) return datos[ini]; //Vector de un solo elemento

	int m = (ini + fin - 1) / 2;
	if (m > 0 && datos[m - 1] < datos[m]) curvaConcava(datos, ini, m);
	else if (m < datos.size() && datos[m + 1] < datos[m]) curvaConcava(datos, m + 1, fin);
	return datos[m];
		
}



bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;

	vector<int> datos;

	for(int i = 0; i < n; i++){
		int aux;
		cin >> aux;
		datos.push_back(aux);
	}

	cout << curvaConcava(datos, 0, datos.size());
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
