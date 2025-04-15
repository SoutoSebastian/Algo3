#include <iostream>
#include <vector> 
#include <utility>
using namespace std;
#include <unordered_set>




bool CA(const vector<vector<int>>& matriz, const int filas, const int columnas){
    
    if(filas== 0 && columnas == 0){
        return true;
    }

    if ((filas + columnas -1) % 2 != 0){
        return false;
    }

    vector<unordered_set<int>> memo(columnas);
    memo[0].insert(matriz[0][0]);
    
    for (int i=0 ; i< filas; i++ ){
        for (int j = 0; j< columnas; j++){
            unordered_set<int> nuevo;

            for (int x: memo[j]){

                if (j + 1 < columnas){
                    int suma = x + matriz[i][j+1];
                    int pasos_restantes = (filas - 1 - i) + (columnas - 1 - (j + 1));
                    if ((abs(suma) <= (pasos_restantes)) && (abs(suma) % 2 == pasos_restantes % 2)){
                        memo[j+1].insert(suma);
                    
                    }
                }    

                if(i + 1 < filas){
                    int suma = x + matriz[i+1][j];
                    int pasos_restantes = (filas - 1 - (i+1)) + (columnas - 1 - j);
                    if ((abs(suma) <= (pasos_restantes)) && (abs(suma) % 2 == pasos_restantes % 2)){
                    
                        nuevo.insert(suma);
                    
                    }
                }    
            }

            if (i + 1 < filas){
            memo[j] = move(nuevo); 
            }

        }
    }

    return (memo[columnas-1].count(0));
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

        
        cout << (CA(matriz, filas, columnas) ? "YES" : "NO") << endl;
    }

    return 0;
}