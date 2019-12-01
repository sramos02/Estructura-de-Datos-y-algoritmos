#include <iostream>
using namespace std;

const int MOD = 31543;

int exp(int x, int n){
    if(n == 0) return 1;

    int p = exp(x, n / 2);
    p = (p * p) % MOD;
    
    if(n % 2 == 0) return p;
    else return (p * x) % MOD;  //Formula proporcionada por el ejercicio
}

int main() {
    int x, n;
    while(cin >> x >> n && (x != 0 || n != 0))
        cout << exp(x%MOD, n) << endl;
    return 0;
}
