/*
* Выполнил: Владимир Матвеев
*
* Задача:  Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
* 
* Честно сказать, не совсем уверен в законности использования std::copy и методов size(), begin() и end() в функции перевода из string в char[].
* С другой стороны, в C++ "из коробки" нет механихма работы со строками, а условие задачи требует подавать данные именно в строке...
* В общем, если я должен был для работы описать свой класс строк и работать с ним, то прошу понять и простить xD.
*
* Отчасти, именно потому, что я не совсем уверен в "честности" своего решения, я и выполнил задачу для char[](как для заменится строк в стандартной библиотеке языка), 
* а работу со string реализовал как надстройку над ним.
*
* Иными словами, если принятое мною решение было не правильным, то это отнюдь не от лени или коварства, а от простого недопонимания. 
* 
*/
#include <conio.h>
#include <iostream>

using namespace std;

int findSumm(char* begin);
char* convert(string str);

int main()
{
	setlocale(LC_CTYPE, "rus");

	char One[] = "A1234567";
	string Two = "A1234567";


	cout << "Sum = " << findSumm(One) << endl;
	
	cout << "Sum = " << findSumm(convert(Two)) << endl;
	_getch();
	return 0;
}

int findSumm(char* begin)
{
	int sum = 0;

	for (int i = 0; i < strlen(begin); i++)
		sum += begin[i];

	return sum;
}

char* convert(string str)
{
	char *a = new char[str.size() + 1];
	a[str.size()] = 0;
	copy(str.begin(), str.end(), a);

	return a;
}
