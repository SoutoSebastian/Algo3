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

    vector<vector<vector<int>>> memo(2, vector<vector<int>>(columnas));

    for (int i=0 ; i< filas; i++ ){
        for (int j = 0; j< columnas; j++){
            if(i==0 && j==0){
                memo[i][j].push_back(matriz[i][j]);
            }

            if (i > 0){
                for (int r = 0; r < memo[0][j].size(); r++){
                    int x = matriz[i][j] + memo[0][j][r];
                    if (abs(x) <= (filas - 1 - i) + (columnas - 1 - j)){
                        memo[1][j].push_back(x);
                    }    
                }
            }
            
            if (j > 0){
                int I = (i == 0 ? 0 : 1);

                for (int r = 0; r < memo[I][j-1].size(); r++){
                    int x = matriz[i][j] + memo[I][j-1][r];
                    if (abs(x) <= (filas - 1 - i) + (columnas - 1 - j)){
                        memo[I][j].push_back(x);
                    }  

                }
            }    
        }

        if (i != 0){
            swap(memo[0], memo[1]);
        }

        for (int j = 0; j < columnas; j++){
            vector<int> vacio;
            memo[1][j] = vacio;
        }
    }
    

   return (!memo[0][columnas-1].empty());

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
