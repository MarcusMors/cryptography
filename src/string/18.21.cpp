#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	string str = "Yo: mucho texto, por favor. Enfatiza, Andre... gritando; timido";
	char arr[str.size()];
	char *pch;

	for (int i = 0; i < str.size(); i++)
		if ((str[i] == ',') || (str[i] == ';') || (str[i] == ':') || (str[i] == '.') || (str[i] == '\'') || (str[i] == '\"'))
			str.replace(i, 1, " ");

	cout << "string : " << str << endl;

	for (int i = 0; i < str.size(); i++)
		arr[i] = str[i];

	cout << "arr : " << arr << endl;

	printf("\n%s\n", arr);
	pch = strtok(arr, " ");

	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	return 0;
}
