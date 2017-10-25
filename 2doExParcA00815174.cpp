/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	2do Examen Parcial
*/

#include <iostream>
using namespace std;

const int INF = 100000000;

int P[100][100]; //Matriz del camino mas corto
char voc[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
			  'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
			  'W', 'X', 'Y', 'Z'}; 
bool pruebas = false;

void printMultiplicacionOptima(int i, int j){
	if (i == j){
		cout << voc[i - 1];
		return;
	}
	else
		cout << "(";
		printMultiplicacionOptima(i, P[i][j]);
		cout << " X ";
		printMultiplicacionOptima(P[i][j] + 1, j);
		cout << ")";
}

int main(){
	int n;
	int D[100][100], ci[100];

		cin >> n;
		// Se guarda en un vector los valores de corte
		for (int i = 0; i <= n; i++){
			cin >> ci[i];
		}
		// Iniciamos la diagonal de la matriz
		for (int i = 1; i <= n; i++){
			D[i][i] = 0;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				P[i][j] = 0;
			}
		}
		// Algoritmo de multiplicacion encadenada de matrices
		for (int diagonal = 1; diagonal <= n - 1; diagonal++){
			for (int i = 1; i <= n - diagonal; i++){
				int j = i + diagonal;
				D[i][j] = INF;
				for (int k = i; k <= j - 1; k++){
					if ((D[i][k] + D[k + 1][j] + ci[i - 1] * ci[k] * ci[j]) < D[i][j]){
						cout << n - diagonal << endl;
						D[i][j] = (D[i][k] + D[k + 1][j] + ci[i - 1] * ci[k] * ci[j]);
						P[i][j] = k;
					}
				}
			}
		}
		if (pruebas){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					if (D[i][j] == 0){
						cout << D[i][j] << "   ";	
					}
					else if (D[i][j] < 100){
						cout << D[i][j] << "  ";
					}
					else
						cout << D[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					cout << P[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		printMultiplicacionOptima(1, n);
		cout << endl;
	return 0;
}