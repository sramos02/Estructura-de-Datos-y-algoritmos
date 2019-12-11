#include <iostream>
#include <vector>
using namespace std;

//P = {0 <= numeros.size && repeciones > 0}
bool cplpyd(vector<int> numeros, int repeticiones) { //return b

	if (numeros.size() == 0) return false;

	int i = 0;
	int aux = numeros.at(0);

	//I = {0 <= i <= j <= numeros.size() && aux == numeros.at(i) && b = dDivertido && cplp}
	//cplp = {PT u: 1 <= u < i : numeros.at(u - 1) < numeros.at(u)}
	//dDivertido = {(PT w: 0 <= w < i : (# k : 0 <= k < j : i) < repetciones}}
	while(i < numeros.size()) {
		i++;

		if (numeros.at(i) == aux) {
			int j = i;
			while((j < numeros.size()) && (numeros.at(j) == aux)) {
				j++;
				if (j - i + 1 > repeticiones) return false;
				else if (j == numeros.size()) return true;
			}
			i = j;
		}
		if((numeros.at(i) > aux + 1) || (numeros.at(i) < aux)) return false;
		aux = numeros.at(i);
	}
	return true;
}
//Q = {b = dDivertido && cplp}
//cplp = {PT u: 1 <= u < numeros.size : numeros.at(u - 1) < numeros.at(u)}
//dDivertido = {(PT w: 0 <= w < numeros.size() : (# k : 0 <= k < numeros.size() : numeros.at(w)) < repetciones}

//fdc = (numeros.size() - i)

//El coste conseguido es LINEAL  O(N) en el caso peor ya que se ejecuta un bucle n veces y dentro de ese bucle
//todas las instrucciones son de coste constante, el bucle interno aumenta la i del mayor por lo que no ejecuta 
//como un bucle diferente

int main() {
	int casos;
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		int repeticiones, longitud;
		vector<int> numeros;

		cin >> repeticiones >> longitud;
		for (int j = 0; j < longitud; j++) {
			int aux;
			cin >> aux;
			numeros.push_back(aux);
		}
		cplpyd(numeros, repeticiones) ? cout << "SI" : cout << "NO";
		cout << endl;
	}
	return 0;
}
