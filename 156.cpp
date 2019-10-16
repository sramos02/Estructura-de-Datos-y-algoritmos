#include <iostream>
using namespace std;

bool resuelveCaso(){
    int v[10000];
    int abs;
    int i = 0, ret = 0;
    bool fin = false;
    
    cin >> v[0]; i++;
    if(v[0] == -1) return true; //Ha llegado al final del programa
    
    while(!fin){
        cin >> v[i];
        if(v[i] != -1) {
            abs = (v[i - 1] - v[i]);        
            if(abs < 0) abs *= -1;
            ret += abs;
        }
        else{ 
            cout << ret << endl;
            fin = true;
        }
        i++;
    }

    return false;
}

int main(){
        bool fin = false;
        while(!fin){
          fin = resuelveCaso();
        }
    return 0;
}
