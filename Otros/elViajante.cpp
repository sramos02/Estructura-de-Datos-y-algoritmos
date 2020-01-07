void elViajante(const vector<vector<int>> distancias, vector<int> solucion, const int n,
                    int costeAct, int nivel, tSolucion & mejorSolucion, vector<bool> marcas){
    int i = 0;
    while( i < n){
        solucion[nivel] = i;
        costeAct += distancias[solucion[nivel-1]][solucion[nivel]];
        int costeEstimado = costeAct + (n-nivel+1)*1; //Tomamos coste 1 como minimo
        if(costeEstimado < mejorSolucion.coste && !marcas[i]){
            if(solucion[nivel] == solucion[0]){
                mejorSolucion.coste = costeAct;
                mejorSolucion.vector = solucion;
            }
        }
        else{
            marcas[i] = true;
            elViajante(distancias, solucion, n, costeAct, nivel + 1, mejorSolucion, marcas);
            marcas[i] = false;
        }
        costeAct -= distancias[solucion[nivel-1]][solucion[nivel]];
        i++;
    }
}
