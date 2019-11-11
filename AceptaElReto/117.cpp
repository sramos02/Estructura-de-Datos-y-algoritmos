//https://www.aceptaelreto.com/problem/statement.php?id=117
#include <iostream>
using namespace std;

void solveCase() {
	string names;

	for (int i = 0; i < 4; i++) cin.get();
	cin >> names;
	cout << "Hola, " + names + "." << endl;
}

int main() {
	unsigned short cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) solveCase();
	return 0;
}
