#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    bool cruce;
    int puntoCruce;
    int ini;
    int fin;
}resultado;

resultado lasLineas(const vector<int> a, const vector<int> b, int ini, int fin){

    int m = (ini + fin) / 2;
    if(a[m] == b[m]) return {true, m, 0, 0};

    if(m < a.size()) {
        if (ini < 0) return {false, 0, -1, 0};

        if (m != 0 && a[m] > b[m] && a[m + 1] > b[m + 1]) return lasLineas(a, b, ini, m);
        else if (a[m] < b[m] && a[m + 1] < b[m + 1]) return lasLineas(a, b, m + 1, fin);
        else if (a[m] < b[m + 1] && b[m] > a[m + 1]) return {false, 0, m, m + 1};
        return {false, 0, a.size() - 1, a.size()};
    }
}

bool resuelveCaso(){
    int n;
    cin >> n;
    if(!cin) return false;

    vector<int> a;
    vector<int> b;

    for(int i = 0; i < 2*n; i++){
        int aux;
        cin >> aux;
        if(i < n) a.push_back(aux);
        else b.push_back(aux);
    }

    resultado res = lasLineas(a, b, 0, n-1);
    if(res.cruce)cout << "SI " << res.puntoCruce << endl;
    else cout <<"NO " << res.ini << " " << res.fin << endl;

    return true;
 }

int main(){
    while(resuelveCaso());
    return 0;
}
