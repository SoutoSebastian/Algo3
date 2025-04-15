#include <iostream>
#include <vector> 
#include <map>
using namespace std;


bool CA(int pasos,int suma, int i, int j, const vector<vector<int>>& matriz, const int filas, const int columnas,  bool& flag){
    suma += matriz[i][j];
    
    if ((filas == 0 && columnas == 0) || flag || abs(suma) > (filas - 1 - i) + (columnas - 1 - j)){
        return false;

    }else if (pasos == (filas - 1) + (columnas -1)){
        if (suma == 0){
            flag = true;
        }
        return (suma == 0);
    
    }else if (i<filas-1 && j<columnas -1){
        return CA(pasos+1, suma , i, j+1, matriz, filas, columnas,flag) || CA(pasos+1, suma , i+1, j, matriz, filas, columnas,flag);
    
    }else if (i == filas -1){
        return CA(pasos+1, suma , i, j+1, matriz, filas, columnas,flag);
    
    }else {
        return CA(pasos+1, suma , i+1, j, matriz, filas, columnas,flag);

    }
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

        bool flag = false;
        
        bool resultado = CA(0, 0, 0, 0, matriz, filas, columnas,flag);
        cout << (resultado ? "YES" : "NO") << endl;
    }

    return 0;
}