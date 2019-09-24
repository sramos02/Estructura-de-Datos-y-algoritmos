https://www.aceptaelreto.com/problem/statement.php?id=368
#include <iostream>
using namespace std;

bool resuelveCaso() {
	long int h;
	int c;

	cin >> h;
	cin >> c;

	if ((c == 0)&&(h == 0)) return false;
	
	if (h < c) cout << "10" << endl;
	else {
		if (h % c > 0) cout << (10 * (h / c)) + 10 << endl;
		else cout << (10 * h / c) << endl;
	}
	return true;
}

int main() {
	bool fin = true;
	while (fin) { fin = resuelveCaso(); }
	return 0;
}
