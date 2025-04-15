#include <iostream>
#include <vector> 
#include <map>
using namespace std;


bool CA(int pasos,int suma, int i, int j, const vector<vector<int>>& matriz, const int filas, const int columnas, map<vector<int>, int>& historial, bool& flag){
    
    
    if ((filas == 0 && columnas == 0) || flag){
        return false;

    }else if(historial.count({pasos,suma,i,j})){
        return false;

    }else if (pasos == (filas - 1) + (columnas -1)){
        suma += matriz[filas-1][columnas-1];
        if (suma == 0){
            flag = true;
        }
        return (suma == 0);
    
    }else if (i<filas-1 && j<columnas -1){
        historial[{pasos, suma,i,j}] = 0;
        return CA(pasos+1, suma + matriz[i][j], i, j+1, matriz, filas, columnas,historial,flag) || CA(pasos+1, suma + matriz[i][j], i+1, j, matriz, filas, columnas,historial,flag);
    
    }else if (i == filas -1){
        historial[{pasos, suma,i,j}] = 0;
        return CA(pasos+1, suma + matriz[i][j], i, j+1, matriz, filas, columnas,historial,flag);
    
    }else {
        historial[{pasos, suma,i,j}] = 0;
        return CA(pasos+1, suma + matriz[i][j], i+1, j, matriz, filas, columnas,historial,flag);

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
        map<vector<int>, int> historial;
        bool resultado = CA(0, 0, 0, 0, matriz, filas, columnas,historial,flag);
        cout << (resultado ? "YES" : "NO") << endl;
    }

    return 0;
}



