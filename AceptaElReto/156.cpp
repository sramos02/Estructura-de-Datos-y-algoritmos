//https://www.aceptaelreto.com/problem/statement.php?id=156
#include <iostream>
using namespace std;

bool solve(int v[]){
	int v[2];       //Vamos comparando todo el rato los ultimos dos que nos entran
    int abs, aux;
    int  ret = 0, i = 1;
    bool end = false;

	cin >> v[0];    //Mete el primero y prepara el segundo
	if (v[0] < 0) return true; //Ha llegado al final del programa


    while (!end) {
            cin >> v[i];
            if (v[i] >= 0) {
                if((aux = (i - 1)) < 0) aux = -aux;  //WARNING Se supone que -1%2 = 1 pero no lo procesa
                abs = (v[aux] - v[i]);  
                if (abs < 0) abs *= -1;
                ret += abs;
            }
            else {
                cout << ret << endl;
                end = true;
            }
            i = ((i + 1) % 2);
        }

    return end;
}

int main() {
	bool end = false;
	while (!solve());
	return 0;
}
