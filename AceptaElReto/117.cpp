//https://www.aceptaelreto.com/problem/statement.php?id=117
#include <iostream>
using namespace std;

void solveCase() {
    string names, basura;

    cin >> basura >> names;
    cout << "Hola, " + names + "." << endl;
}

int main() {
    unsigned short cases;
    cin >> cases;
    for (unsigned short i = 0; i < cases; i++) solveCase();
}
