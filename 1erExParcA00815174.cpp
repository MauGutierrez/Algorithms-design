/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	1er Examen Parcial
*/

#include <iostream>
#include <time.h>

using namespace std;

int n, m;
int terreno[20][20]; // Matriz original donde se plantaran las bombas
int terrenoAux[20][20]; // Matriz auxiliar

// Funcion que busca las minas en la matriz original y rellena la matriz auxiliar.
// Encuentra la posicion de la bomba en la matriz original si es un numero diferente a 0.
// Al encontrar la posicion, comenzara a llenar las casillas vecinas de la bomba con '1' 
// Para llenar las casillas vecinas se formaron submatrices dentro de la matriz auxiliar
// siendo estas de tamaño 2n + 1 por 2n + 1 donde n es el numero de la bomba encontrada.
// Al final las casillas que queden con 0 seran las no afectadas.
// La matriz auxiliar se extendio 3 renglones y 3 columnas mas de la original para no tener problemas al ser llenada,
// en caso de que la bomba se encuentre en las orillas.

void buscaMinas(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (terreno[i][j] != 0){
				for (int a = 0; a < (terreno[i][j] * 2) + 1; a++){
					for (int b = 0; b < (terreno[i][j] * 2) + 1; b++){
						if (i - terreno[i][j] + 3 + a < n + 3 && j - terreno[i][j] + 3 + b < m + 3){
							terrenoAux[i - terreno[i][j] + 3 + a][j - terreno[i][j] + 3 + b] = 1;
						}
					}
				}
			}
		}
	}
}

void leyendoTerreno(int a, int b){
	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			cin >> terreno[i][j];
		}
	}
	cout << endl;
}

int main(){
	cout << "Introduce n y m: ";
	cin >> n >> m;
	int celdasNoAfectadas = n*m;
	cout << endl;
	leyendoTerreno(n, m);
	buscaMinas();
	for (int i = 3; i < n + 3; i++){
		for (int j = 3; j < m + 3; j++){
			if (terrenoAux[i][j] != 0){
				celdasNoAfectadas--;
			}
		}
	}
	cout << celdasNoAfectadas <<endl;
	return 0;
}