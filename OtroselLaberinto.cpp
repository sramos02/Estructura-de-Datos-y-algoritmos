#include <vector>
using namespace std;

struct tCasilla{
    int fila;
    int columna;
};

bool esValida(const vector<vector<bool>> laberinto, tCasilla c, int n, vector<vector<bool>> marcas){
    return c.fila >= 0 && c.columna >= 0 && c.fila < n && c.columna < n && laberinto[c.fila][c.columna] && !marcas[c.fila][c.columna];
}

void labertinto(const vector<vector<bool>> laberinto, vector<tCasilla> solucion, int nivel, int n, vector<vector<bool>> marcas){
    int i = 0;
    while(i < 4){ //Las 4 direcciones
        solucion[nivel] = sigDireccion(i, solucion[nivel-1]);
        if(esValida(laberinto, solucion[nivel], n, marcas)){
            if(solucion[nivel].fila == n - 1 && solucion[nivel].columna == n - 1) tratarSolucion();
            else{
                marcas[solucion[nivel].fila][solucion[nivel].columna] = true;
                labertinto(laberinto, solucion, nivel+1, n, marcas);
            }
        }
        i++;
    }
}

