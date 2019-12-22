#include <iostream>
#include <vector>
using namespace std;

//Coste O(logN) con respecto al tamaño del vector
int elBongo(const vector<int> datos, const int cont, int  ini, int fin){

    if(ini == fin){
        if((cont + ini) == datos[ini]) return datos[ini];
        else return -1;
    }

    int m = (ini + fin) / 2;
    if(m != (datos.size() - 1) && (cont + m) < datos[m]) return elBongo(datos, cont, ini, m);
    else if (m != 0 && (cont + m) > datos[m]) return elBongo(datos, cont, m + 1, fin);
    else return datos[m];
}
    
int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        int n, cont;
        vector<int> datos;
        cin >> n >> cont;

        for (int j = 0; j < n; j++) {
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }
        int ret = elBongo(datos, cont, 0, datos.size() - 1);
        (ret == -1)?cout << "NO":cout << ret;
        cout << endl;
    }
    return 0;
}
