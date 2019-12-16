#include <iostream>
#include <math.h>
using namespace std;

void comp(int n, int & complementario, int & complementarioInv) {
	if (n < 10) {
		complementario = 9 - n;
		complementarioInv = complementario;
	}
	else {
		comp(n / 10, complementario, complementarioInv);
		int cmp = 9 - (n % 10);
		complementario = complementario * 10 + cmp;
		complementarioInv = cmp * (pow(10, (int)log10(n))) + complementarioInv;
	}
}


int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		long int n;
		cin >> n;

		int res, resInv;
		comp(n, res, resInv);
		cout << res << " " << resInv << endl;
	}
	system("PAUSE");
	return 0;
}
