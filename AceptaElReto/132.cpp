//https://www.aceptaelreto.com/problem/statement.php?id=132
#include <iostream>
#include <string>
using namespace std;

//P = {0 <= i < j <= word.length}
bool solve(int i, int j, const string word){

    //I = {ret = PT u : i <= j : word[u] == word[j]}
	while (i <= j) {
		if (word[i] != word[j]) ret = false;
		i++;
	}

	return ret;
}
//Q = {ret = PT u : i <= u <= j : word[u] == word[j]}

bool solveCase(const string word) {
	bool ret = true;
    int aux, i, j;
	cin >> i >> j;

	//I is always the minimun position
    if (i > j) {
		aux = i;
		i = j;
		j = aux;
	}

    return solve(i, j, word);
}

int main() {

	string word;
	int cases;

	getline(cin, word);
	cin >> cases;

    while (i < numCasos) {
		cout << (solveCase(palabra) ? "SI" : "NO") << endl;
		i++;

		if (i == numCasos) {
			cout << endl;

			cin.get();
			getline(cin, palabra);

			cin >> numCasos;
			i = 0;
		}
	}
    
	return 0;
}
