#include <iostream>
using namespace std;

//P = {0 <= n <= v.length}
int solve(int v[], int n){
    int ret = 0, hg = 0;
    for (int i = n - 1; i >= 0; i--) {
	if (v[i] > hg) {
		hg = v[i];
		ret++;
	}
    }
    return ret;
}
//Q = {ret = max(u: n-1 >= i >= 0 && v[u] > hg: V[i]}

bool solveCase() {
    int n;
    int v[100000];

    cin >> n;
    if (n == 0) return false;

    for (int i = 0; i < n; i++)	cin >> v[i];
    cout << solve(v, n) << endl;
    return true;
}

int main() {
	while (solveCase());
	return 0;
}
