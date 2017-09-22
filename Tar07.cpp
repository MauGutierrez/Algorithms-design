/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Tarea 7 Triomino
*/

#include <iostream>
using namespace std;


int matrix[16][16]; // Matriz donde se dibujara el triomino con un tamaño maximo de 16 x 16
int n; // Tamaño de la matriz introducio por el usuario
int filledRow; // Primera fila ocupada
int filledColumn; // Primera columna ocupada
int Number = 1; // Contador que lleva el numero utilizado para formar la figura del triominio

// Partimos la matriz en cuadrantes: 1, 2, 3 y 4.
// Al partir la matriz en cuadrantes utilizamos esta funcion para encontrar
// en que cuadrante se encuentra la casilla ocupada.
// Ejemplo: En una matriz de 2 x 2 si la casilla ocupada se encuentra en
// 			matriz[1][1] el cuadrante es el numero 4
// Recibe como parametro: 
//						r -> fila ocupada
//						c -> columna ocuapda
//						s -> Tamañao de la matriz recibida
int buscaCuadrante(int r, int c, int s){
	int cuadrante = 1;
	// Cuadrante 2 o 3
	if (c < s / 2){
		cuadrante++;
	}
	// Cuadrante 1 o 4
	else{

	}
	if (r < s / 2){
		if (cuadrante == 1){
			cuadrante = 1;
		}
		else 
			cuadrante = 2;
	}
	else{
		if (cuadrante == 1){
			cuadrante = 4;
		}
		else
			cuadrante = 3;
	}
	return cuadrante;

}


// Funcion utilizada para desarrollar el triomino.
// Recibe como parametro:
//						 occupiedRow -> Fila ocupada
//						 occupiedColumn -> Columna ocupada
//						 actualRow -> Fila donde comenzamos a contar en la matriz
//						 actualColumn -> Columna donde comenzamos a contar en la matriz
//						 size -> Tamaño de la matriz
void Triomine(int occupiedRow, int occupiedColumn, int actualRow, int actualColumn, int size){
	if (size >= 2){
		// Buscamos el cuadrante
		int cuad = buscaCuadrante(occupiedRow - actualRow, occupiedColumn - actualColumn, size);
		// columna_izq -> columna izquierda
		// columna_der -> columna derecha
		// fila_a -> fila arriba
		// fila_b -> fila abajo 
		int columna_izq, columna_der, fila_a, fila_b;
		// La fila de arriba y la columna de izquierda siempre se van a encontrar a la mitad de la matriz
		fila_a = columna_izq = (size - 1) / 2;
		// La fila de abajo y la columna de abajo siempre se van a encontrar una correnada después de 
		// la columna izquierda y la fila de arriba  
		fila_b = columna_der = fila_a + 1;

		// Sumamos el valor actual para obtener las coordenadas en la matriz original
		columna_izq += actualColumn;
		columna_der += actualColumn;
		fila_a += actualRow;
		fila_b += actualRow;

		// Inicialmente se rellenan las casillas que se encuentran en el centro de la matriz
		// y a partir de eso se divide la matriz para formar submatrices en las que iremos siguiendo el mismo procedimiento
		// recursivamente: buscar el cuadrante ocupado y rellenar el centro de la matriz.  
		switch(cuad){
			case 1:
				matrix[fila_a][columna_izq] = Number;
				matrix[fila_b][columna_izq] = Number;
				matrix[fila_b][columna_der] = Number;
				Number++;
				Triomine(occupiedRow, occupiedColumn, fila_a - (size - 1) / 2, columna_der, size / 2);
				Triomine(fila_a, columna_izq, fila_a - (size - 1) / 2, columna_izq - (size - 1) / 2, size / 2);
				Triomine(fila_b, columna_izq, fila_b, columna_izq - (size - 1) / 2, size / 2 );
				Triomine(fila_b, columna_der, fila_b, columna_der, size / 2);
				break;

			case 2:
				matrix[fila_a][columna_der] = Number;
				matrix[fila_b][columna_izq] = Number;
				matrix[fila_b][columna_der] = Number;
				Number++;
				Triomine(occupiedRow, occupiedColumn, fila_a - (size - 1) / 2, columna_izq - (size - 1) / 2, size / 2);
				Triomine(fila_a, columna_der, fila_a - (size - 1) / 2, columna_der, size / 2);
				Triomine(fila_b, columna_der, fila_b, columna_der, size / 2);
				Triomine(fila_b, columna_izq, fila_b, columna_izq - (size - 1) / 2, size / 2);
				break;

			case 3:
				matrix[fila_a][columna_izq] = Number;
				matrix[fila_a][columna_der] = Number;
				matrix[fila_b][columna_der] = Number;
				Number++;
				Triomine(occupiedRow, occupiedColumn, fila_b, columna_izq - (size - 1) / 2, size / 2);
				Triomine(fila_b, columna_der, fila_b, columna_der, size / 2);
				Triomine(fila_a, columna_der, fila_a - (size - 1) / 2, columna_der, size / 2);
				Triomine(fila_a, columna_izq, fila_a - (size - 1) / 2, columna_izq - (size - 1) / 2, size / 2);			
				break;

			case 4:
				matrix[fila_a][columna_izq] = Number;
				matrix[fila_a][columna_der] = Number;
				matrix[fila_b][columna_izq] = Number;
				Number++;
				Triomine(occupiedRow, occupiedColumn, fila_b, columna_der, size / 2);
				Triomine(fila_b, columna_izq, fila_b, columna_izq - (size - 1) / 2, size / 2);
				Triomine(fila_a, columna_izq, fila_a - (size - 1) / 2, columna_izq - (size - 1) / 2, size / 2);
				Triomine(fila_a, columna_der, fila_a - (size - 1) / 2, columna_der, size / 2);
				break;
		}

	}
}

int main(){
	cout << "Introduce el tamaño de la matriz: ";
	cin >> n;
	cout << "Introduce la casilla: ";
	cin >> filledRow >> filledColumn;
	matrix[filledRow][filledColumn] = 0;
	Triomine(filledRow, filledColumn, 0, 0, n);
	cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			if (matrix[i][j] >= 10){
				cout << matrix[i][j] << " ";
			}
			else
				cout << matrix[i][j] << "  ";
		cout << endl;
	}
}