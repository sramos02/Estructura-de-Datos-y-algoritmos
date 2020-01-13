#include <iostream>
#include <vector>
using namespace std;

//Ejercicio 1
struct tSolucion{
    int ini = 0;
    int fin = 0;
};

//P: {0 <= n <= long(datos)}
tSolucion secMasLargaConsecutivosCrecientes(const int n, const vector<int> datos){
    //A0
    tSolucion ret;
    tSolucion act;
    int i = 0;

    //I = {0 <= i <= n && (act = PT u,w : 0 <= u < w <= i && consecutivosCrecientes(u, w) : w - u)) && ret = (ret = max u,w : 0 <= u < w <= i && consecutivosCrecientes(u, w) : w - u))}
    //consecutivosCrecientes(u, w): {PT p : u <= p < w : datos[p] < datos[p+1]}
    while(i < n){
        //A1
        if(datos[i] - datos[i+1] == -1  || datos[i] - datos[i+1] == 0){
           act.fin++;
            if(abs(datos[ret.fin] - datos[ret.ini]) < abs(datos[act.fin] - datos[act.ini])){
                ret.ini = act.ini;
                ret.fin = act.fin;
            }
        }
        else{
            act.ini  = i+1;
            act.fin = i+1;
        }
        //R = {0 <= i+1 <= n && (act = PT u,w : 0 <= u < w <= i+1 && consecutivosCrecientes(u, w) : w - u)) && ret = (ret = max u,w : 0 <= u < w <= i+1 && consecutivosCrecientes(u, w) : w - u))}
        //A2
        i++;
    }
    //I && !B
    return ret;
}
//Q: {ret = max u,w : 0 <= u < w <= n && consecutivosCrecientes(u, w) : w - u)}
//consecutivosCrecientes(u, w): {PT p : u <= p < w : datos[p] < datos[p+1]}

//funcion de cota = {n-i} La i va aumentando en cada iteración y, como n es constante, llegará un momento en el que se anulen
//El coste del algoritmo es O(N), tenemos un bulce que se ejecuta n veces siendo el resto de instucciones, las del interior del bucle incluidas, constantes

int main(){
    int n;
    cin >> n;
    while(n > 0){
        vector<int> datos;
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }
        tSolucion ret = secMasLargaConsecutivosCrecientes(n, datos);
        cout << ret.ini << " " << ret.fin << endl;
        cin >> n;
    }
}


//Ejercicio 2

//Coste O(logN) en relación con el numero de elementos del vector
//El vector divide a la mitad todo el rato hasta encontrar un numero igual o mayor y uno menor
int elCercano(const vector<int> datos, const int x, int ini, int fin, int mejorSol){

    //Calculo para dividir
    int m = (ini + fin) / 2;

    //Actualización
    if(datos[m] == x) return x;
    else if (abs(x - datos[m]) < abs(x - datos[mejorSol])) mejorSol = m;

    if(x <= datos[m]) for(int i = 0; m > 0 && datos[m - i - 1] == datos[m]; i--) m--;
    else  for(int i = 0; m < datos.size()-1 && datos[m + i + 1] == datos[m]; i++)m++;

    //Movimiento

    if(abs(mejorSol - m) == 1) return datos[mejorSol];
    else if(m > 0 && x <= datos[m]) elCercano(datos, x, ini, m, mejorSol);
    else if (m < datos.size() && x >= datos[m]) return elCercano(datos, x, m + 1, fin, mejorSol);

}

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int x, n;
        vector<int> datos;

        cin >> x >> n;
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }
        cout << elCercano(datos, x, 0, datos.size() - 1, 0);
    }

    return 0;
}


//Ejercicio 3

void lasQuitanieves(const vector<int> anchurasM, const vector<int> anchurasN, const vector<vector<int>> calidades,
                    int nivel, int solAct, vector<bool> marcasN,
                    int & mejorSol){
    int i = 0;
    while(i < anchurasN.size()) {
        if (!marcasN[i] && anchurasM >= anchurasN) {
            solAct += calidades[nivel][i];
            if(nivel == anchurasM.size()){ 
                if(solAct > mejorSol) mejorSol = solAct;
            }
            else { //NoEsSolucion
                marcasN[i] = false;
                lasQuitanieves(anchurasM, anchurasN, calidades, nivel + 1, solAct, marcasN, mejorSol);
                marcasN[i] = true;
            }
        }
    }
}

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int m, n;
        vector<int> anchurasM;
        vector<int> anchurasN;
        vector<bool> marcasN;
        vector<vector<int>> calidades;

        cin >> m >> n;
        for(int u = 0; u < m; u++) cin >> anchurasM[u];
        for(int v = 0; v < n; v++){
            cin >> anchurasN[v];
            marcasN[v] = true;
        } 

        for(int u = 0; u < m; u++){
            for(int v = 0; v < n; v++){
                cin >> calidades[u][v];
            }
        }

        int sol;
        lasQuitanieves(anchurasM, anchurasN, calidades, 0, 0, marcasN, sol);
        cout << sol << endl;
    }
    return 0;
}
