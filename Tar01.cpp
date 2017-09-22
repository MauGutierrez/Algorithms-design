/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Tarea 1 finding the unique char
*/

#include <iostream>
using namespace std;

// Funcion utilizada para encontrar e imprimir el unico caracter
// Recibe como parametros el string donde se buscara el unico caracter
// y la longitud del string donde se buscara el caracter
void binarySearch(string myString, int size){
	// Calcula la mitad del string
	// A partir de ahi compara con los caracteres que tiene a los lados
	// Al calcular la mitad, se tienen dos posibilidades:
	// 		1) Que al dividir a la mitad el string el string resultante sea par 
	//		2) Que al dividir a la mitad el string el string resultante sea impar
	// Se observa que:
	//		1) Cuando se es par, el caracter unico esta hacia donde se encuentre el caracter igual 
	//		   al que se encuentra en la mitad
	//		   Ejemplo: aabb c cdde
	//					abbc c ddee
	//		2) Cuando se es impar, el caracter unico esta hacia donde se encuentre el caracter diferente
	//		   al que se encuentra en la mitad
	//		   Ejemplo: aab b ccd
	//					aab c cdd
	//	La manera de encontrar el caracter unico sera cuando el caracter que se encuentra en la posicion media
	//	sea diferente a los que se encuentran a su lado
	// Se podria decir que es una especie de busqueda binaria ya que en base a calcular la mitad
	// se eliminan otras opciones haciendo mas eficiente la busqueda.
	int mid = size / 2, low = mid - 1, high = mid + 1;
	if (myString[mid] != myString[low] && myString[mid] != myString[high]){
		cout << myString[mid] << endl;
		return;
	}
	else if (mid % 2 == 0){
		if (myString[mid] == myString[low]){ 
			 myString = myString.erase(mid + 1, mid);
		}
		else if (myString[mid] == myString[high]){
			myString = myString.erase(0, mid + 2);	
		}
	}
	else{
		if (myString[mid] != myString[low]){
			myString = myString.erase(mid, mid + 1);
		}
		else if (myString[mid] != myString[high]){
			myString = myString.erase(0, mid + 1);
		}
	}
	binarySearch(myString, myString.length());
}


int main(){
	string palabra;
	cout << "Ingrese el string: ";
	cin >> palabra;
	binarySearch(palabra, palabra.length());
	return 0;
}