#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    bool cruce;
    int puntoCruce;
    int ini;
    int fin;
}resultado;



bool crece(const vector<int> a, const vector<int>  b, const int i, const int j){
    if (a[i] <= a[j] && b[i] >= b[j] && a[i] > b[i]) return true;
    else if(b[i] <= b[j] && a[i] >= a[j] && a[i] < b[i]) return true;
    else return false;
}

bool decrece(const vector<int> a, const vector<int> b, const int i, const int j){
    if(a[i] >= a[j] && b[i] <= b[j] && a[i] > b[i]) return true;
    else if (b[i] >= b[j] && a[i] <= a[j] && a[i] < b[i]) return true;
    else return false;
}

bool cruce(const vector<int> a, const vector<int> b, const int i, const int j){
    if(a[i] <= b[j] && b[i] >= a[j]) return true;
    // else if (b[i] >= a[j] && a[i] <= b[j]) return true;
    return false;
}

resultado lasLineas(const vector<int> a, const vector<int> b, int ini, int fin){

    //Caso base 1 elemento
    if(a.size() == 1) return{false, 0, 0, 1};

    int m = (ini + fin) / 2;
    if(a[m] == b[m]) return {true, m, 0, 0};

    //Extremo
    if (m == 0) {
        if (cruce(a, b, m, m + 1)) return {false, 0, m, m + 1};
        else return {false, 0, -1, 0};
    }

    if(m < a.size()) {
        if (crece(a, b, m, m + 1)) return lasLineas(a, b, ini, m);
        else if (decrece(a, b, m, m + 1)) return lasLineas(a, b, m + 1, fin);
        else if (cruce(a, b, m, m + 1)) return {false, 0, m, m + 1};
        else return {false, 0, (const int) a.size() - 1, (const int) a.size()};
    }
}

bool resuelveCaso(){
    int n;
    cin >> n;
    if(n == 0) return false;

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
