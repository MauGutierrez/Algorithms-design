/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Tarea 8 Audiophobia
*/

#include <iostream>
#include <climits>
using namespace std;

int D[105][105]; // Matriz de adyacentes
int resultado[105];
int n;

void initMatrix(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			D[i][j] = INT_MAX;
		}
		D[i][i] = 0;
	}
}

void floyd(){
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));
			}
		}
	}
}

int main(){
	int cases, m, q, Ai, Bi, Ci, aux = 1, cont = 1, indice = 1;
	cin >> cases;
	while (cases > 0){
		cin >> n >> m >> q;
		aux += q;
		initMatrix();
		for (int i = 1; i <= m; i++){
			cin >> Ai >> Bi >> Ci;
			D[Ai][Bi] = Ci;
			D[Bi][Ai] = Ci;
		}
		floyd();
		for (int i = 1; i <= q; i++){
			cin >> Ai >> Bi;
			if (D[Ai][Bi] == INT_MAX){
				resultado[cont] = 0;
			}
			else{
				resultado[cont] = D[Ai][Bi];
			}
			cont++;	
		}
		resultado[q + 1] = -1;
		cont++;
		cases--;
	}
	cout << endl;
	for (int i = 1; i <= aux; i++){
			if (i == 1){
				cout << "Case " << indice << ": " << endl;
				indice++;
			}
			else if (resultado[i] == -1){
				cout << "Case " << indice << ": " << endl;
				indice++;
			}
			if (resultado[i] == 0){
				cout << "No path" << endl;
			}
			if (resultado[i] != 0 && resultado[i] != -1)
				cout << resultado[i] << endl;
	}
}