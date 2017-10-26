/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Tarea 13 La familia Telerin
*/

#include <iostream>
using namespace std;

const int INF = 1000;
int L[105], T[105];
int W[105][105];
int n, vmin;
bool done[105];
int contadorNodos = 0;
bool continueCount = false;
int nextNode;


int main(){
	int m, a, b, r;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			W[i][j] = INF;
		}
		W[i][i] = 0;
		done[i] = true;
	}
	
	for (int i = 1; i <= m; i++){
		cin >> a >> b >> r;
		W[a][b] = r;
		W[b][a] = r; 
	}

	for (int i = 2; i <= n; i++){
		L[i] = W[1][i];
		T[i] = 1;
	}

	for (int d = 1; d < n - 1; d++){
		int min = INF;
		for (int i = 2; i <= n; i++){
			if (0 <= L[i] && L[i] <= min && done[i] != false){
				min = L[i];
				vmin = i;
			}
		}

		for (int i = 2; i <= n; i++){
			if (L[vmin] + W[vmin][i] < L[i]){
				L[i] = L[vmin] + W[vmin][i];
				T[i] = vmin;
				
			}
		}
		done[vmin] = false;
	}
	cout << endl;
	for (int i = 2; i <= n; i++){
		if (T[i] != 1){
			continueCount = true;
			contadorNodos += 1;
		}
		nextNode = T[i];
		while (continueCount){
			if (T[nextNode] != 1){
				continueCount = true;
				contadorNodos += 1;
				nextNode = T[nextNode];
			} 
			continueCount = false;
		}
		cout << i << " " << L[i] << " " << contadorNodos << " " << endl;
		contadorNodos = 0;
	}

	return 0;
}