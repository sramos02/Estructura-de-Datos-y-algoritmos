#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


bool resuelveCaso(string v, int p, int q) {
    
    while(v[p] == ' ') p++;
    while(v[q] == ' ') q--;
    
    if(q-p <= 1){
        if(v[p] == v[q])return true;
        return false;
    }
    
    return (v[p] == v[q]) && resuelveCaso(v, p+1, q-1);
}

int main() {
	string c;
    getline(cin, c);
    while(c != "XXX"){
        for(int i = 0; i < c.length(); i++) c[i] = toupper(c[i]);
        resuelveCaso(c, 0, c.length() - 1)?cout << "SI":cout << "NO";
        cout << endl;
        getline(cin, c);    
    }
	return 0;
}
