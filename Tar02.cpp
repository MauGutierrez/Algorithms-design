/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Tarea 2 Zeros and Ones
*/

#include <iostream>
using namespace std;


int main(){
	int n = 0, cant = 0;
	string cadena;
	cout << "n: ";
	cin >> n;
	cin >> cadena;
	for (int i = 0; i <= n; i++){
		if (cadena[i] == '0'){
			cant++;
		}
		else if (cadena[i] == '1'){
			cant--;
		}	
    }
    cout << abs(cant) << endl;
	return 0;
}