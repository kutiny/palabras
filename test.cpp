
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
	string s;
	cout << "Escriba aqui su texto: ";
	cin >> s;
	cout << "\nEl texto ingresado es: " << s << endl;
	cin.ignore(2);
}
