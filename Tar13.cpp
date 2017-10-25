#include <iostream>
#include <climits>

using namespace std;

int L[105], T[105];
int W[105][105];
int n;

void Dijkstra(){
	for (int i = 2; i <= n; i++){
		L[i] = W[1][i];
		T[i] = 1;
	}
	for (int i = 0; i <= n - 1; i++){
		int min = INT_MAX, vmin;
		for (int i = 2; i <= n; i++){
			if (0 <= L[i] <= min){
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
	}
}

int main(){

}