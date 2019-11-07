//https://www.aceptaelreto.com/problem/statement.php?id=167
#include <iostream>
using namespace std;


int resolver(int l){
    if(l == 1) return 4;
    return (4 * l) + (4 * resolver(l/2));
}

bool resuelveCaso() {
    int l;
    
    cin >> l;
    if(!cin) return false;  
    cout << resolver(l) << endl;
    
    return true;
}

int main() {
	   
	while(resuelveCaso());
	return 0;
}
