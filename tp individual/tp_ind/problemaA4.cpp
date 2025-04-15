#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;





bool CA(const vector<vector<int>>& matriz, const int filas, const int columnas){
    
    if ((filas + columnas -1) % 2 != 0){
        return false;
    }

    if(filas== 0 && columnas == 0){
        return true;
    }

    const int rango = 2 * (filas + columnas - 1) + 1;
    const int correccion = filas + columnas -1;
    vector<vector<vector<char>>> memo(2, vector<vector<char>>(columnas, vector<char>(rango, 0)));

    
    for (int i = 0; i< filas; i++){
        for (int j = 0; j< columnas; j++){
            if(i==0 && j == 0){
                memo[i][j][matriz[0][0] + correccion] = true;

            }

            if (i > 0){
                for (int suma = 0; suma < rango; suma++){
                    if(memo[0][j][suma]){
                        int nueva_suma = suma + matriz[i][j];
                        if (0 <= nueva_suma && nueva_suma < rango){
                            memo[1][j][nueva_suma] = true;
                        }
                    }
                }
            }

            if (j > 0){

                int I = 1;
                if (i == 0){
                    I = 0;
                }

                for (int suma = 0; suma < rango; suma++){
                    if(memo[I][j-1][suma]){
                        int nueva_suma = suma + matriz[i][j];
                        if (0 <= nueva_suma && nueva_suma < rango){
                            memo[I][j][nueva_suma] = true;
                        }
                    }
                }
            }
        }

        if (i != 0){
            swap(memo[0] , memo[1]);
        }
        for (int j = 0; j < columnas; j++){
            fill(memo[1][j].begin(), memo[1][j].end(), 0);
        }
   }

   return (memo[0][columnas-1][correccion]);
}


int main(){
    int t;
    cin >> t;

    for(int caso = 0; caso < t; caso++) {
        int filas;
        cin >> filas;
        int columnas;
        cin >> columnas;

        vector<vector<int>> matriz(filas, vector<int>(columnas));
        for(int i = 0; i<filas; i++){
            for(int j = 0; j<columnas; j++){
                cin >> matriz[i][j];
            }

        }

        
        bool resultado = CA(matriz, filas, columnas);
        cout << (resultado ? "YES" : "NO") << endl;
    }

    return 0;
}
