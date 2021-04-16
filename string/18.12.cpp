#include <iostream>
#include <string>
using namespace std;

void printDoll(int state)
{
	if (state == 1)
	{
		cout << " O " << endl;
	}
	else if (state == 2)
	{
		cout << " O " << endl;
		cout << "/" << endl;
	}
	else if (state == 3)
	{
		cout << " O " << endl;
		cout << "/|" << endl;
	}
	else if (state == 4)
	{
		cout << " O " << endl;
		cout << "/|\\" << endl;
	}
	else if (state == 5)
	{
		cout << " O " << endl;
		cout << "/|\\" << endl;
		cout << " |" << endl;
	}
	else if (state == 6)
	{
		cout << " O " << endl;
		cout << "/|\\" << endl;
		cout << " |" << endl;
		cout << "/" << endl;
	}
	else
	{
		cout << " O " << endl;
		cout << "/|\\" << endl;
		cout << " |" << endl;
		cout << "/ \\" << endl;
	}
}

int main()
{
	string words[6] = {"gato", "conejo", "perro", "copernico", "americio", "aluminio"};
	bool again = true;
	string command;
	while (again)
	{
		string word;
		int size = word.size();
		int n;
		cout << "ingrese un número de 0 a 6: ";
		cin >> n;
		word = words[n];
		string clue = "";
		clue.resize(word.size(), 'X');
		char letter;
		int cont = 0;
		int state = 0;
		int attemp = 0;
		while (cont < word.size())
		{
			bool flag = true;
			cout << "Adivine la palabra :\t" << clue << endl;
			cout << "=> ";
			cin >> letter;
			letter = tolower(letter);
			attemp++;
			for (int i = 0; i < word.size(); i++)
				if (word[i] == letter)
				{
					clue[i] = word[i];
					cont++;
					flag = false;
				}

			if (flag)
				state++;

			if (state > 0)
			{
				printDoll(state);
				if (state == 7)
					cout << "Perdiste. Suerte a la próxima" << endl;
			}
			cout << "intentos : " << attemp << endl;
		}
		cout << "Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no" << endl;
		cin >> command;
		if (command.size() == 2)
		{
			if ((toupper(command[0]) == 'N') && (toupper(command[1]) == 'O'))
				return 0;
			else if ((toupper(command[0]) != 'S') && (toupper(command[1]) != 'I'))
				cout << "no reconocemos el comando ingresado." << endl;
		}
	}

	return 0;
}
