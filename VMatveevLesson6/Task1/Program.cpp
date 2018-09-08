/*
* ��������: �������� �������
*
* ������:  ����������� ���������� ���-�������. �� ���� ������� �������� ������, �� ������ ����� ����� ��������.
* 
* ������ �������, �� ������ ������ � ���������� ������������� std::copy � ������� size(), begin() � end() � ������� �������� �� string � char[].
* � ������ �������, � C++ "�� �������" ��� ��������� ������ �� ��������, � ������� ������ ������� �������� ������ ������ � ������...
* � �����, ���� � ������ ��� ��� ������ ������� ���� ����� ����� � �������� � ���, �� ����� ������ � �������� xD.
*
* �������, ������ ������, ��� � �� ������ ������ � "���������" ������ �������, � � �������� ������ ��� char[](��� ��� ��������� ����� � ����������� ���������� �����), 
* � ������ �� string ���������� ��� ���������� ��� ���.
*
* ����� �������, ���� �������� ���� ������� ���� �� ����������, �� ��� ������ �� �� ���� ��� ���������, � �� �������� �������������. 
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
