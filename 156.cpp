#include <iostream>
using namespace std;

int resuelveCaso(int v[]){
    int i = 1, ret = 0;

    while(v[i] != -1){
        int abs = (v[i - 1] - v[i]);
        if(abs < 0) abs *= -1;

        ret += abs;
        i++;
    }

    return ret;
}

int main(){
    int v[10000];
    int i = 1;
    bool fin = false;

    //Lee hasta que encuentra el -1 y lo guarda todo en v

        while(!fin){
            cin >> v[i];
            //Aqui ha encontrado el -1 y ha metido todo lo anterior en v
            if(v[i] == -1)
                if(i == 0)fin = true; 
                else {
                    cout << resuelveCaso(v) << endl; 
                    i = 0;
                }
        }
    return 0;
}
