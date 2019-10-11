#include <iostream>
using namespace std;


bool resuelveCaso() {
	int n;
	int ret = 0, mayor = 0;

	int v[100000];

	cin >> n;
	if (n == 0) return false;


	for (int i = 0; i < n; i++)	cin >> v[i];

	for (int i = n - 1; i >= 0; i--) {
		if (v[i] > mayor) {
			mayor = v[i];
			ret++;
		}
	}

	cout << ret << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
