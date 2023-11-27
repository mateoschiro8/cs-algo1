#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int minim(vector<int> &v, int low, int high) {
    int index = low;
    for(int i = low; i < high; ++i) {
        if(v[index] > v[i])
            index = i;
    }
    return index;
}

void swap(vector<int> &v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void insert(vector<int> &v, int i, int j) {
    vector<int> temp;
    for (int k = 0; k < v.size() + 1; ++k) {
        if(k < j)
            temp.push_back(v[k]);
        else if(k == j)
            temp.push_back(v[i]);
        else if(k - 1 != i)
            temp.push_back(v[k - 1]);
    }
    v = temp;
}

void insertionSort(vector<int> &v){
	//Rellenar insertion
    for (int i = 1; i < v.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if (v[0] > v[i])
                insert(v, 0, i);
            else if(v[j] <= v[i] && v[j + 1] > v[i]) {
                insert(v, j + 1, i);
            }
        }
    }
}

void selectionSort(vector<int> &arr){
	//Rellenar selection
    for (int i = 0; i < arr.size(); ++i) {
        int min = minim(arr, i, arr.size());
        swap(arr, i, min);
    }
}

void ordenar(vector<int> &items){
    	//Poner aca una implementación de ordenar
}

int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	}
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);
		restos.insert(restoAct);
	}
	return res;
}

int main(){
	int N, W, aux;

	//Se levantan los items y la capacidad del contenedor
	cout << "Se levantan los items y la capacidad del contenedor";
	ifstream bpp("BPP.in");
	bpp >> N >> W;
	vector<int> items;
	for(int i=0; i<N; ++i){
		bpp >> aux;
		items.push_back(aux);
	}
	bpp.close();
	//Se corre best-fit
	int cant1 = bestFit(W, items);
	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

	//Se ordenan los items
	ordenar(items);
	//Se corre best-fit-decreasing
	int cant2 = bestFit(W, items);
	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

	return 0;
}


