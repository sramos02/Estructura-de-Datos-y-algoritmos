#include <iostream>
#include <fstream>
using namespace std;

void cargarVector(int v[], const int n){
	for (int i = 0; i < n; i++) cin >> v[i]; //O(N)
}

void resuelveCaso() {
	int n;
	int v[10000];
	int valles = 0, picos = 0;

	cin >> n;

	//Casos base, hay menos de tres elementos
	cargarVector(v, n);

	if (n < 3) cout << "0 0" << endl;
	else {
		//O(N)
		for (int i = 2; i < n; i++) {
			if ((v[i - 1] > v[i - 2]) && (v[i - 1] > v[i])) picos++;
			else if ((v[i - 1] < v[i - 2]) && (v[i - 1] < v[i])) valles++;
		}

		cout << picos << " " << valles << endl;
	}
}

int main() {

	// Para la entrada por fichero.
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif


	unsigned int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
