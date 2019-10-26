#include <iostream>
using namespace std;

//P = {0 <= n <= long(v) && PTi : 0 <= i < n : v[i] > 0}
void resuelveCaso(int & n, int v[]) { //return w, m
	int i = 0;

	// I = {0 <= i <= j <= (n - (#y : 0 <= y < n : V[y] % 2 != 0)) && (PT y : i <= y <= n && v[y] % 2 == 0 : w[y] = v[y]) && (PT y : i <= y < n && v[y] % 2 != 0 : modVector(u, w, n, y)}
	// modVector(u, w, n, y) = {PT x : 0 <= x < y : w[x] = v[x] && PT x : y <= x < n - 1: w[x] = v[x + 1]}

	while (i < n) {
		if (v[i] % 2 != 0) {
			int j = i;
			while (j < n) {
				v[j] = v[j + 1];
				j++;
			}
			n--;
		}
		else i++;
	}
}
//Q = {(PT y : 0 <= y <= n && v[y] % 2 == 0 : w[y] = v[y]) && (PT y : 0 <= y < n && v[y] % 2 != 0 : modVector(u, w, n, y) && m = n - (#y : 0 <= y < n : V[y] % 2 != 0)}
// modVector(u, w, n, y) = {PT x : 0 <= x < y: w[x] = v[x] && PT x : y <= x < n - 1: w[x] = v[x + 1]}

// El coste del algoritmo es O(N log n) ya que el priemr bucle se ejecuta N veces recorriendo todo el vector, sin embargo, dentro de el
// tiene otro bucle que se ejecuta N veces en la primera iteración y va decreciendo hasta llegar a 1. El resto de instrucciones son O(1) 
// por lo que no realizan ninguna modificación en el coste del mismo

//función de cota del primer bucle: n - i
//función de cota del segundo bucle: n - j

int main() {
	int n;
	cin >> n;

	while (n != -1) {
		int v[1000];

		for (int i = 0; i < n; i++) cin >> v[i];
		resuelveCaso(n, v);
		for (int i = 0; i < n; i++) cout << v[i]  << " ";
		cout << endl;
		cin >> n;
	}
}
