#include <iostream>
#include <vector>
using namespace std;


char quienFalta(vector<char> datos, int ini, int fin) {
    int iniAux = datos[0];
    if (ini + 1 == fin) return datos[ini]; //Vector de un solo elemento

	int m = (ini + fin - 1) / 2;
	if (m > 0 && iniAux + m < iniAux-datos[m]) return curvaConcava(datos, ini, m);
	else if (m < datos.size() && iniAux+m < iniAux-datos[m]) return curvaConcava(datos, m + 1, fin);
	return datos[m] - 1;
}



bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;

	char primero, ultimo, aux;
	vector<char> datos;

    cin >> primero;
	cin >> segundo;
		
	for(int i = 0; 1 < (segundo - primero); i++){    
		cin >> aux;
		datos.push_back(aux);
	}

	cout << quienFalta(datos, 0, datos.size()) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
