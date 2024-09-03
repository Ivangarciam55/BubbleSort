#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void bSort();
unsigned t0, t1;


int main() {
    t0 = clock();
    bSort();
    t1 = clock();
    double time = (static_cast<double>(t1 - t0)/CLOCKS_PER_SEC);
    cout << endl << "Tiempo de ejecucion: " << time << endl;
    return 0;
}

void bSort() {
    int tam;
    cout << "Ingrese el tamano del arreglo" <<endl;
    cin >> tam;
    int num[tam];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 99999999);

    cout << "Desordenado" << endl;

    for (int i = 0; i < tam; ++i) {
        num[i] = dis(gen);
    }
    for (int i = 0; i < tam; ++i) {
        cout << num[i] << " ";
    }

    cout << endl << "Ordenado" << endl;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam-i-1; j++) {
            if(num[j] > num[j +1]) {
                const int pos = num[j];
                num[j] = num[j +1];
                num[j +1] = pos;
            }
        }
    }

    for(int i = 0; i < tam; i++) {
        cout << num[i] << " ";
    }
}