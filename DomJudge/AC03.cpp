#include <iostream>
#include <vector>
using namespace std;

//P = {0 <= v.size() && Eu: 0 <= u < v.size() : t < v[u] && t > 0}
void solveCase(vector<int> v, int t, int & retP, int & retQ) {
	int sum = 0, max = 0;			//Variables
	int q = v.size() - 1, p = q;    //Auxiliar iterators

	while (p >= 0) {

		if (v.at(p) <= t) {
			while (v.at(p) <= t && p > 0) p--; //Reset state
			q = p;
			sum = 0;
		}
		else sum++;

		if (sum >= max) {					 //Actualiz. max
			max = sum;
			retQ = q;
			retP = p;
		}	
		
		p--;
	}
}
//Q = {retP = Ep q: 0 <= p <= q < v.size() && min(isValid(v, p, q, t): p && retQ = Ep q: 0 <= p <= q < v.size() && min(isValid(v, p, q, t): q}
// isValid(v, p, q, t) = {PT u: p <= u <= q: v[u] > t}

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int n, t;
		vector<int> v;

		cin >> n >> t;
		for (int j = 0; j < n; j++) {
			int aux;
			cin >> aux;
			v.push_back(aux);
		}
		
		int retP, retQ;
		solveCase(v, t, retP, retQ);
		cout << retP << " " << retQ << endl;
	}
}
