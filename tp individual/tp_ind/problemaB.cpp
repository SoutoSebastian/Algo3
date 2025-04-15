#include <iostream>
#include <vector> 
#include <iomanip>
using namespace std;


int suma(string v){
    int res = 0;

    for (int i = 0; i < v.size(); i++){
        if (v[i] == '+'){
            res++;
        }else{
            res--;
        }
    }

    return res;
}

void Hilocomunicados (string s1, string s2,int i, double& casospos, double& casosbien){

    if (s1.size() == 0){
        casospos = 1;
        casosbien = 1;

    }else if (i == s1.size()){

        casospos++;
        
        if (suma(s1) == suma(s2)){
            casosbien++;
        }
    }else{

        if (s2[i] != '?'){
            Hilocomunicados(s1, s2, i+1, casospos, casosbien);
        }else{
            s2[i] = '+';
            Hilocomunicados(s1, s2, i+1, casospos, casosbien);
            s2[i] = '-';
            Hilocomunicados(s1, s2, i+1, casospos, casosbien);
        }
    }
}


int main(){
    string s1, s2;

    cin >> s1;
    cin >> s2;

    double casospos = 0;
    double casosbien = 0;

    Hilocomunicados(s1, s2, 0, casospos, casosbien);

    double proba = static_cast<double>(casosbien) / casospos;

    cout << fixed << setprecision(12) << proba << endl;

    return 0; 

}