#include <iostream>
#include <vector> 
using namespace std;
#include <unordered_set>


unordered_set<int> unionConj(const unordered_set<int>& a, const unordered_set<int>& b){
    unordered_set<int> C = a;

    C.insert(b.begin(), b.end());
    return C;
}

unordered_set<int> sumaConj(const unordered_set<int>& a, int b, int i, int j, int filas, int columnas){
    unordered_set<int> res;

    for (int x :a){
        if ((abs(x + b) <= (filas - 1 - i) + (columnas - 1 - j)) && ((x+b != 0) || ((filas - 1 - i) + (columnas - 1 - j)) % 2 == 0)){
            res.insert(x + b);
        } 
    }
    
    return res;
}

bool CA(const vector<vector<int>>& matriz, const int filas, const int columnas){
    
    if(filas== 0 && columnas == 0){
        return true;
    }

    if ((filas + columnas -1) % 2 != 0){
        return false;
    }

    vector<unordered_set<int>> memo(columnas);

    
    for (int i=0 ; i< filas; i++ ){
        for (int j = 0; j< columnas; j++){
            if (i == 0 && j == 0){
                memo[j].insert(matriz[0][0]);
            }else if (i == 0){
                memo[j] = sumaConj(memo[j-1], matriz[i][j], i, j, filas, columnas);
            }else if (j == 0){
                memo[j] = sumaConj(memo[j], matriz[i][j], i, j, filas, columnas);
            }else {
                auto izquierda = sumaConj(memo[j - 1], matriz[i][j], i, j, filas, columnas);
                auto arriba = sumaConj(memo[j], matriz[i][j], i, j, filas, columnas);
                memo[j] = unionConj(izquierda, arriba);
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
