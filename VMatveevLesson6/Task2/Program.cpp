/*
* Выполнил: Владимир Матвеев
*
* Задача:  Переписать программу, реализующее двоичное дерево поиска.
* а) Добавить в него обход дерева различными способами;
* б) Реализовать поиск в двоичном дереве поиска;
*
*/
#include <iostream>
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
		if (tmp->info)
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

int main()
{
	setlocale(LC_CTYPE, "rus");

	int m[10] = {6,2,1,4,10,3,5,8,7,9};

	for (int i = 0; i < 10; ++i)
	{

		push(m[i], &tree, &root);
	}
//	printTree(root, 0);
	printTreeStr(tree);
	cout << endl;
	cout << "КЛП: ";
	klp(tree);
	cout << endl;
	cout << "ЛКП: ";
	lkp(tree);
	cout << endl;
	cout << "ЛПК: ";
	lpk(tree);
	cout << endl;
	findElement(4, root);
	_getch();
}
