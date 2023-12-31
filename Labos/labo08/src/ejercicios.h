#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, char delim);
string darVueltaPalabra(string s);
bool subsecuencia(string s1, string s2);
vector<vector<string> > agruparAnagramas(vector<string> v);
bool esPalindromo(string s);
bool tieneRepetidos(string s);
string rotar(string s, int j);
string darVueltaK(string s, int k);
string abueloLaino(string s);
int cantidadDeFelicitaciones(vector<string> v);
int middleOut(string s, string t);

vector<string> splitAux(string s, char delim, int index);
bool esAnagrama(string v1, string v2);
int cantApariciones(char t, string s);
void remover(string &s, int index);