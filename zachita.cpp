#include <iostream>

using namespace std;

struct Tree
{
	int value;
	Tree* right;
	Tree* left;

	Tree()
	{
		value = 0;
		right = NULL;
		left = NULL;
	}
};

struct spis {
	int value;
	spis* pointer;
	spis() {
		value = 0;
		pointer = ;
	}
};


void AddToList(spis*& first, int n)
{
	spis* l = first;
	spis* p = NULL;

	while (true)
	{
		bool b = false;
		if (l != NULL)
		{
			b = l->value < n;
		}

		if (b)
		{
			p = l;
			l = l->pointer;
		}
		else
		{
			ListElement* el = new ListElement();
			el->value = n;

			el->pointer = l;
			if (p != NULL)
			{
				p->pointer = el;
			}
			else
			{
				first = el;
			}
			break;
		}
	}
}

void InputList(spis*& first)
{
	spis* p = first;

	int n = 10000000;

	int i = 0;
	while (i < n)
	{
		AddToList(first, 2);
		i++;
	}
}



void Input(Tree*& el, int v)// Ввод дерева
{
	if (el == NULL)
	{
		el = new Tree();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}

void Output(Tree* el)// Вывод дерева
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
	}

}


void Spisok(Tree*& head, spis* el, Tree*& p)//Список с деревом
{
	if (head != NULL)
	{
		Tree* root = new Tree;
		Spisok(head, el->left, p);
		root->value = head->value;
		if (p == NULL)
		{
			head = p1;
			p = p1;
		}
		else
		{
			p->pointer = p1;
			p = p1;
		}
		Spisok(head, el->right, p);
	}
}

void Out(spis* l) {//Вывод списка
	cout << "Spisok: ";
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}

int NodeCount(Tree* node)
{
	if (node->left == NULL && node->right == NULL)
		return 1;
	int left, right;
	if (node->left != NULL)
		left = NodeCount(node->left);
	else
		left = 0;
	if (node->right != NULL)
		right = NodeCount(node->right);
	else
		right = 0;

	return left + right + 1;
}


int Sum(Tree* el)
{
	/*
	Данныя функция найдет сумму элементов в поддереве, на которое ссылает el.
	Сначала она посчитает сумму для левого поддерева (el->left).
	Потом она посчитает сумму для правого поддерева (el->rigth).
	Далее она сложит две найденные суммы между собой и прибавит к ним значение элемента,
	которое хранится в el->value
	Возможная ошибка: поиск суммы в el, в то время, как el == NULL.
	Чтобы ее избежать, вводится простая соответствующая проверка.
	Если проверка не пройдена, то функция вернет 0.
	*/
	if (el != NULL)
	{
		int l = Sum(el->left); //сумма для левого поддерева
		int r = Sum(el->right); //сумма для правого поддерева

		return l + r + el->value;
	}
	else
	{
		return 0;
	}
}

int main() {
	Tree* root = NULL;
	Tree* first = NULL;
	spis* head;

	spis* p = head;
	while (p != NULL)
	{
		(p->value % 2 == 0)
	{
		int v = p->value;
		input(root, v);
		p = p->pointer;
	}
	else {
	p = p->pointer;
}
	}



	system("pause");
}
