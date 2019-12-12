#include <iostream>
#include <vector>
using namespace std;

//P = {0 < datos.size() && 0 < minimo}
vector<int> laCasaDeHeidi(vector<int> datos, int minimo, int & secMasLarga, int & numLlanos) {
	vector<int> resultado;
	int j = datos.size() - 1, i;

	//Busca mayor y solo comprueba despues de él
	int altMax = datos[datos.size() - 1];
	int longitud = 1;

	//Nos quedamos el caso 0 fuera para comprobar al final
	while (j > 1) {
		if (datos[j - 1] == datos[j]) longitud++;
		else {
			if (datos[j - 1] < datos[j]);
			else altMax = datos[j];

			if (longitud >= minimo) {
				if(longitud > secMasLarga) secMasLarga = longitud;
				resultado.push_back(datos.size() - j - 1); 
				numLlanos++;
			}
			longitud = 1;
		}
		j--;
	}

	//  j = 0 // Solo entra si el resultado lleva a una posible solución
	if (longitud + 1 >= minimo && datos[j] == datos[j + 1]) {
		longitud++;
		if (longitud > secMasLarga) secMasLarga = longitud;
		resultado.push_back(datos.size() - j - 1);
		numLlanos++;
	}

	return resultado;
}
//Q = resultado(u) = {PT u, w :(0 <= u <= w < datos.size()) && (PT k: u <= k <= w: datos[k] = datos.at[u] && esAccesible(datos, k)) : ((w - u) >= minimo)}
// esAccesible(datos, k) = {PT v: k <= v < w : datos[v] <= datos[k]}

bool resuelveCaso() {
	int n, minimo;
	int secMasLarga = 0, numLlanos = 0;
	vector<int> datos;
	
	cin >> n >> minimo;
	for (int i = 0; i < n; i++) {
		int aux;
		cin >> aux;
		datos.push_back(aux);
	}

	vector<int> ret = laCasaDeHeidi(datos, minimo, secMasLarga, numLlanos);

	//Mostrar solución
	cout << secMasLarga << " " << numLlanos << " ";
	for (int i = numLlanos - 1; i >= 0; i--) cout << ret[i] << " ";
	cout << endl;

	//Retorno
	if (secMasLarga == 0 && numLlanos == 0) return false;
	return true;
}

int main() {
	while (resuelveCaso());
	system("PAUSE");
	return 0;
}
