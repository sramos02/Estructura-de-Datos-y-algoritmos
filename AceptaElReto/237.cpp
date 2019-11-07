#include <iostream>
#include <math.h>
using namespace std;


int resolver(long long n, int l){
    if(l == 1) return 0;
    else if(n%l == 0) return 1;
    resolver(n/10, l-1);
}

bool resuelveCaso() {
    long long n;
    
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
