//
#include <iostream>
using namespace std;


bool resolver(long long n){
    return false;
}

bool resuelveCaso() {
    long long n;
    
    cin >> n;
    if(!cin) return false;  
    resolver(n)?cout << "POLIDIVISIBLE": cout << "NO POLIDIVISIBLE";
    cout << endl;
    return true;
}

int main() {
	   
	while(resuelveCaso());
	return 0;
}
