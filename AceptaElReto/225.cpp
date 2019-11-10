//https://www.aceptaelreto.com/problem/statement.php?id=225
#include <iostream>
using namespace std;

long long int fibMod(int n, int x, int y) {
	if (n == 0) return x;
	if (n == 1) return y;
	return ((fibMod(n - 1, x, y) + fibMod(n - 2, x, y)) % 1000000007);
}

bool solveCase() {
	int n, x, y;
	cin >> n >> x >> y;

	if (!cin) return false;

	cout << fibMod(n, x, y) << endl;
	return true;
}


int main() {
	while (solveCase());
}
