#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
    s += delim;
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != delim)
            temp += s[i];
        else {
            if (temp.length() > 0){
                v.push_back(temp);
                temp = "";
            }
        }
    }
	return v;
}

string darVueltaPalabra(string s){
	vector<string> temp = split(s, ' ');
    string res = "";
    for (int i = 0; i < temp.size(); ++i) {
        if(i < temp.size() - 1)
            res = res + temp[temp.size() - i - 1] + " ";
        else
            res = res + temp[temp.size() - i - 1];
    }
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
	int cont = 0;
    int i = 0, j = 0;
    while(i < s1.length()) {
        while(j < s2.length()) {
            if(s1[i] == s2[j]) {
                cont++;
                i++; j++;
            } else {
                j++;
            }
        }
        i++;
    }
	return cont == s1.length();
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string>> res = {};
    res.push_back({v[0]});
    int i = 1;
    for (int j = 0; j < res.size(); j++) {
        while(i < v.size()) {
            if(esAnagrama(v[i], res[j][0])) {
                res[j].push_back(v[i]);
                i++; j = 0;
            } else if (j == res.size() - 1) {
                res.push_back({v[i]});
                i++; j = 0;
            } else {
                j++;
            }
        }
    }
    return res;
}

bool esAnagrama(string v1, string v2) {
    bool esAnagr = true;
    for (int i = 0; i < v1.size(); ++i) {
        if(cantApariciones(v1[i], v1) != cantApariciones(v1[i], v2))
            esAnagr = false;
    }
    for (int i = 0; i < v2.size(); ++i) {
        if(cantApariciones(v2[i], v2) != cantApariciones(v2[i], v1))
            esAnagr = false;
    }
    return esAnagr && (v1.length() == v2.length());
}

int cantApariciones(char t, string s){
    int cant = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == t)
            cant++;
    }
    return cant;
}

bool esPalindromo(string s){
    int i = 0, siz = s.size();
    while(i < siz/2 && s[i] == s[siz - 1 - i])
        i++;
	return i == siz/2;
}

bool tieneRepetidos(string s){
	bool repetidos = false;
    for (int i = 0; i < s.length(); ++i) {
        if (cantApariciones(s[i], s) > 1)
            repetidos = true;
    }
	return repetidos;
}

string rotar(string s, int j){
    for (int i = 0; i < j; ++i) {
        s = s[s.size() - 1] + s;
        remover(s, s.size() - 1);
    }
	return s;
}

void remover(string &s, int index) {
    string temp = "";
    for (int i = 0; i < s.length(); ++i) {
        if(i != index)
            temp.push_back(s[i]);
    }
    s = temp;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res, temp;
    int j = 0;
    int resto = s.length() % k;
    for (int i = 0; i < s.length(); i+=k) {
        if(resto != 0) {
            for (int l = 0; l < resto; ++l)
                temp.push_back(s[s.size() - resto + l]);
            for (int l = 1; l <= resto; ++l)
                remover(s, s.size() - 1);
            s = darVueltaK(s, k) + darVueltaK(temp, resto);
            i = s.length();
        } else {
            while (j < k) {
                res.push_back(s[i + k - 1 - j]);
                j++;
            }
            for (int l = 0; l < k + i; ++l)
                remover(s, 0);
            s = res + s;
            j = 0;
        }
    }
	return s;
}

string abueloLaino(string s){
    string res;
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){

    return 0;
}
