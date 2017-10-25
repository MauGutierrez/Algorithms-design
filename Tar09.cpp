#include <iostream>
using namespace std;

const int INF = 100000000;

int main(){
	int l, n;
	int D[100][100], ci[100];

	while (true){
		// Se introducen los valores de L y N
		cin >> l;
		if (l == 0){
			break;
		}
		cin >> n;
		// Se guarda en un vector los valores de corte
		for (int i = 1; i <= n; i++){
			cin >> ci[i];
		}
		ci[0] = 0;
		ci[n + 1] = l;
		// Iniciamos la diagonal de la matriz
		for (int i = 1; i <= n; i++){
			D[i][i] = 0;
		}
		// Algoritmo de multiplicacion encadenada de matrices
		for (int diagonal = 3; diagonal <= n + 2; diagonal++){
			for (int i = 0; i <= n + 2 - diagonal; i++){
				int j = i + diagonal - 1;
				D[i][j] = INF;
				for (int k = i; k < j; k++){
					D[i][j] = min(D[i][j],D[i][k] + D[k][j] + ci[j] - ci[i]);
				}
			}
		}
		cout << "The minimum cutting is "<< D[0][n + 1]<<"."<<endl;
	}
	return 0;
}