#include <iostream>
#include <vector>
using namespace std;

bool llamadaRara(vector<int> numeros, int pibote) {
	int elem = numeros.at(pibote);

	for (int i = 0; i < (int)numeros.size(); i++) {
		if (numeros.at(i) < elem) return false;
	}
	return true;
}

int main(){
	int casos, longitud, pibote;

	cin >> casos;
	for (int j = 0; j < casos; j++) {
		vector<int> numeros;

		cin >> longitud >> pibote;
		for (int i = 0; i < longitud; i++) {
			int aux;
			cin >> aux;
			numeros.push_back(aux);
		}

		if(longitud > 0) llamadaRara(numeros, pibote)?cout << "SI" : cout << "NO";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
