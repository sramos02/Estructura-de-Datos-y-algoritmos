//SERGIO RAMOS MESA
#include <iostream>
using namespace std;

void resuelveCaso() {
	int n, V[10000];
	int valles = 0, picos = 0;
	cin >> n;

	//Casos base, hay menos de tres elementos
	if (n < 3) cout << "0 0" << endl;
	else {

		cin >> V[0];
		cin >> V[1];

		//Un valle o un pico nunca puede estar en los extremos  O(N)
		for (int i = 2; i < n; i++) {
			cin >> V[i];
			if ((V[i - 1] > V[i - 2]) && (V[i - 1] > V[i])) picos++;
			else if ((V[i - 1] < V[i - 2]) && (V[i - 1] < V[i])) valles++;
		}

		cout << picos << " " << valles << endl;
	}
}

int main() {
	int casos;
	cin >> casos;

	for (int i = 0; i < casos; i++) resuelveCaso();
	return 0;
}