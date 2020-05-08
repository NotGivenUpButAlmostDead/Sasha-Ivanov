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
		pointer = NULL;
	}
};


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

void Detach(Tree* root, Tree* el)// Обнуления ссылки на корень
{
	if (root == NULL || el == NULL)
	{
		return;
	}
	else if (root->left == el)
	{
		root->left = NULL;
	}
	else if (root->right == el)
	{
		root->right = NULL;
	}
	{
		Detach(root->left, el);
		Detach(root->right, el);
	}
}
void Remove(Tree* el)//Удаления корня и подкорня
{
	if (el != NULL)
	{
		Remove(el->left);
		Remove(el->right);
		delete el;
	}
}
Tree* Find(Tree* el, int v)// Поиск корня
{
	Tree* result = NULL;
	if (el == NULL)
	{
		result = NULL;
	}
	else if (el->value == v)
	{
		result = el;
	}
	else
	{
		result = Find(el->left, v);
		if (result == NULL)
		{
			result = Find(el->right, v);
		}
	}
	return result;
}

void Spisok(spis*& head, Tree* el, spis*& p)//Список с деревом
{
	if (el != NULL)
	{
		spis* p1 = new spis;
		Spisok(head, el->left, p);
		p1->value = el->value;
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


const Tree* node_max(const Tree* tr) {//Максимум дерева(интернет)
	if (tr == NULL)
		return NULL;

	const Tree* p = tr;
	while (p->right != NULL)
		p = p->right;
	return p;
}


Tree* Max(Tree* root) {//Максимум дерева
	while (root->right) {
		root = root->right;
	}
	return root;
}

Tree* Min(Tree* root) {//Минимум дерева
	while (root->left) {
		root = root->left;
	}
	return root;
}

Tree* udal_hecnhet(Tree* root) //Функция удаления четных листьев бинарного дерева
{
	if (!root)
		return 0;
	if (!root->left && !root->right && !(root->value % 2))
	{
		delete(root);
		return 0;
	}
	root->left = udal_hecnhet(root->left);
	root->right = udal_hecnhet(root->right);
	return root;
}


int main() {
	Tree* root = NULL;
	spis* first = NULL;
	spis* two = NULL;
	cout << "Vvedite kolichestvo dereva = ";
	int n, x;
	cin >> n;
	cout << "Vvedite elementi dereva = ";
	for (int i = 0; i < n; i++)
	{
		//cin >> x;
		x = rand() % 100;
		Input(root, x);
	}
	cout << endl;

	cout << "Derevo: ";//Вывод дерева
	Output(root);
	cout << endl;

	Spisok(first, root, two);//Вывод списка (которое преобразовано)
	Out(first);

	Tree* e3 = Max(root);//Максимум дерева
	cout << "Max = " << e3->value;
	cout << endl;

	Tree* e4 = Min(root);//Минимум дерева
	cout << "Min = " << e4->value;
	cout << endl;

	int sumchis;//Сумма минимума и максимума
	cout << "Summa min max = " << e4->value + e3->value;
	cout << endl;

	//int ud;//Удаления корня дерева
	//cout << endl;
	//cout << "VVedite koren kotoriy udaliti = ";
	//cin >> ud;
	//Tree* e = Find(root, ud);
	//Detach(root, e);
	//Remove(e);
	//cout << endl;

	//cout << "Derevo bes kornya: ";
	//Output(root);
	//cout << endl;

	//Tree* e1 = Find(root, ud);
	//Detach(root, e1);
	//Remove(e1);
	//cout << endl;
	//cout << endl;
	//cout << "////////Dopolnitelinay proverka//////// " << endl;
	//cout << "Derevo bes kornya: ";
	//Output(root);
	//cout << endl;

	int raz;
	cout << "VVedite koren kotoriy razdel = ";
	cin >> raz;
	Tree* e6 = Find(root, raz);
	Detach(root, e6);
	cout << "Derevo otsoedinenoe: ";
	Output(root);
	cout << endl;

	cout << "Derevo otsoedinenoe 2: ";
	Output(e6);
	cout << endl;

	Tree* e5 = udal_hecnhet(root);// Удаления нечетных элементов
	cout << "Derevo bes chet: ";
	Output(root);
	cout << endl;


	system("pause");
}
