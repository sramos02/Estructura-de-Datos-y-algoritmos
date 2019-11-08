#include <iostream>
using namespace std;

int resuelveCaso(int n, int nBase, int coef){
    
    if(n != 0) return resuelveCaso(n/6, nBase + coef*(n%6), coef * 10);
    return nBase;
}

int main(){
    int casos;
    cin >> casos;
    
    for(int i = 0; i < casos; i++) {
        int n;
        cin >> n;
        cout << resuelveCaso(n, 0, 1) << endl;
    }
    return 0;
}
