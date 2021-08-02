#include <iostream>

using namespace std;

int main()
{
	string nombre;
	string apellido;
	cout << "ingrese el nombre : ";
	cin >> nombre;
	cout << "ingrese el apellido : ";
	cin >> apellido;
	string nombreYapellido = nombre + ' ' + apellido;
	cout << nombreYapellido << endl;
	return 0;
}
