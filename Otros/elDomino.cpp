//Encontrar una solución ciclica que resuelva una partida de dominó
//Utilizamos vuelta atras para la resolución

#include <iostream>
#include <vector>
using namespace std;

void muestraResultado(vector<int> sol){
    //trivial
}

void domino(vector<int> sol, int nivel, const int n, vector<vector<bool>> marcas, bool & fin){
    int i = 0;
    int m = (n * n + n)/2;

    while(i < n && !fin){
        if(!marcas[sol[nivel-1]][i]){
            sol[nivel] = i;
            if(nivel == m){
                if(sol[0] == sol[m]) {
                    muestraResultado(sol);
                    fin = true;
                }
            }
            else{
                marcas[sol[nivel-1]][i] = true;
                marcas[i][sol[nivel-1]] = true;
                domino(sol, nivel + 1, n, marcas, fin);
                marcas[sol[nivel-1]][i] = false;
                marcas[i][sol[nivel-1]] = false;

            }
        }
        i++;
    }
}
