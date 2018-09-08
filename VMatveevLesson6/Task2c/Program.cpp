/*
* Выполнил: Владимир Матвеев
*
* Задача:  Переписать программу, реализующее двоичное дерево поиска.
* в) *Добавить в программу обработку командной строки с помощью которой можно 
* указывать из какого файла считывать данные, каким образом обходить дерево.
*
* Данные в файле подаются сразу, без указания размера. Т.е. все данные из файла попадут в дерево.
*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct node
{
	int info;
	node *l, *r, *p;
};

int step = 0;
node *root = NULL;
node *tree = NULL;

void push(int a, node **tmp, node **parent)
{
	if ((*tmp) == NULL)
	{
		(*tmp) = new node;
		(*tmp)->info = a;
		(*tmp)->l = (*tmp)->r = NULL;
		(*tmp)->p = (*parent);

		if (!(*parent))
			root = (*tmp);

		return;
	}

	if (a > (*tmp)->info) 
		push(a, &(*tmp)->r, &(*tmp));
	else 
		push(a, &(*tmp)->l, &(*tmp));
}

void printTree(node *tmp, int level)
{
	if (tmp)
	{
		printTree(tmp->l, level + 1);
		for (int i = 0; i < level; i++) 
			cout << "   ";
		cout << tmp->info << endl;
		printTree(tmp->r, level + 1);
	}
}

void printTreeStr(node *tmp)
{
	if (tmp)
	{
		cout << tmp->info;
		if (tmp->info) // or (node->l || node->r)
		{
			cout << "(";
			if (tmp->l)
				printTreeStr(tmp->l);
			else
				cout << "N";

			cout << ",";

			if (tmp->r)
				printTreeStr(tmp->r);
			else
				cout << "N";

			cout << ")";
		}
	}
}

void klp(node *tmp)
{
	if (tmp)
	{
		cout << tmp->info << " ";
		klp(tmp->l);
		klp(tmp->r);
	}
}

void lkp(node *tmp)
{
	if (tmp)
	{
		lkp(tmp->l);
		cout << tmp->info << " ";
		lkp(tmp->r);
	}
}

void lpk(node *tmp)
{
	if (tmp)
	{
		lkp(tmp->l);
		lkp(tmp->r);
		cout << tmp->info << " ";
	}
}

void findElement(int x, node *tmp)
{
	if (tmp)
	{
		if (x == tmp->info)
		{
			cout << "Нашли за " << step << " итерации" << endl;
		}
		else if (x < tmp->info)
		{
			step++;
			findElement(x, tmp->l);
		}
		else if (x > tmp->info)
		{
			step++;
			findElement(x, tmp->r);
		}
	}
	else
		cout << "Ничерта не нашли" << endl;
}

int menuNubmerFour()
{
	int a;
	cout << "Введите число для поиска: ";
	cin >> a;
	return a;
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	int a;
	int menu = -1;
	string fileName;
	ifstream F;
//	F.open("data.txt", ios::in);
	while (true)
	{
		cout << endl;
		cout << "Ведите имя файла или неберите quit для выхода: ";
		cin >> fileName;
		F.open(fileName, ios::in);
		if (fileName == "quit")
			return 1;
		if (F)
			break;
	}

	if (F)
	{
		while (!F.eof())
		{
			F >> a;
			push(a, &tree, &root);
		}
	}
	else
	{
		cout << "Error";
		_getch();
		return 1;
	}
//	printTree(root, 0);
	cout << "Дерево в скобочной записи: ";
	printTreeStr(tree);
	while (menu != 0)
	{
		cout << "Выбирите действие" << endl;
		cout << "КЛП - 1\nЛКП - 2\nЛПК - 3\nПоиск - 4\nВыход - 0\n: ";
		cin >> menu;

		switch (menu)
		{
		case 0:
			cout << "Bye!";
			break;
		case 1:
			cout << "КЛП: ";
			klp(tree);
			break;
		case 2:
			cout << "ЛКП: ";
			lkp(tree);
			break;
		case 3:
			cout << "ЛПК: ";
			lpk(tree);
			break;
		case 4:
			findElement(menuNubmerFour(), root);
			break;
		}
	}
	_getch();
	return 0;
}
