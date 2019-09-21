#include <iostream>
using namespace std;


void resuelveCaso() {
	string nombre;

	for (int i = 0; i < 4; i++) cin.get(); //Elimina "Hola soy ", coste CONSTANTE O(1)
	cin >> nombre;
	cout << "Hola, " + nombre + "." << endl;
}

int main() {
	unsigned short casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) resuelveCaso();
	return 0;
}
