#include <iostream>
using namespace std;

int main() {
    int objetivo;
    cin >> objetivo;

    const int filas = 3, columnas = 4;
    int matriz[filas][columnas];
    int suma = 0;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> matriz[i][j];
            suma += matriz[i][j];
        }
    }

    cout << "Suma total: " << suma << endl;

    if (suma == objetivo) {
        cout << "La suma coincide con el número objetivo ✅" << endl;
    } else {
        cout << "La suma NO coincide con el número objetivo ❌" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector> 
using namespace std;
#include <unordered_set>



bool CA(const vector<vector<int>>& matriz, const int filas, const int columnas){
    
    if(filas== 0 && columnas == 0){
        return true;
    }

    int rango = 2 * (filas + columnas - 1) + 1;
    int correccion = filas + columnas -1;
    vector<vector<vector<bool>>> memo(filas, vector<vector<bool>>(columnas, vector<bool>(rango, false)));
    
   for (int i = 0; i< filas; i++){
        for (int j = 0; j< columnas; j++){
            if(i==0 && j == 0){
                memo[i][j][matriz[0][0] + correccion] = true;
            }
            if (i > 0){
                for (int suma = 0; suma < rango; suma++){
                    if(memo[i-1][j][suma]){
                        int nueva_suma = suma + matriz[i][j];
                        if (0 <= nueva_suma && nueva_suma < rango){
                            memo[i][j][nueva_suma] = true;
                        }
                    }
                }
            }
            if (j > 0){
                for (int suma = 0; suma < rango; suma++){
                    if(memo[i][j-1][suma]){
                        int nueva_suma = suma + matriz[i][j];
                        if (0 <= nueva_suma && nueva_suma < rango){
                            memo[i][j][nueva_suma] = true;
                        }
                    }
                }
            }
        }
   }

   return (memo[filas-1][columnas-1][correccion]);
}