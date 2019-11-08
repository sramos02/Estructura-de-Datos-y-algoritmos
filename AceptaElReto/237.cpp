#include <iostream>
#include <math.h>
using namespace std;


bool resolver(long long int n, int l){
    if(l == 1) return true;
    return resolver(n/10, l-1) && (n%l == 0);
}

bool resuelveCaso() {
    long long int n;
    
    cin >> n;
    if(!cin) return false;  
    
    int l = floor(log10(n)) + 1;
    resolver(n, l)?cout << "POLIDIVISIBLE": cout << "NO POLIDIVISIBLE";
    cout << endl;
    return true;
}

int main() {
	   
	while(resuelveCaso());
	return 0;
}
