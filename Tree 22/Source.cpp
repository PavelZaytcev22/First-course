#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int tabs = 0;
int kol = 0;

class tree
{
	friend class  TreePrint;
public:
	//Конструкторы и деструктор
	tree();
	tree(int data);
	~tree();
	//Функция добавления узла 
	void Add(int data, tree*& tr);
	//Функция печати дерева
	void print_tree(int level);

	//Функция получения уровня дерева 
	int getHeight(tree* tr);
	tree* rotateRight(tree* y);
	tree* rotateLeft(tree* x);
	tree* insertBT(tree* tr, int data);

	//Обходы дерева 
	void pr_obh(tree* tr);                 
	void sim_obh(tree* tr);                
	void obr_obh(tree* tr);     
	//Функция проверки на заполнненость
	bool is_empty(tree*& tr);          
	//Функция удаления дерева или поддерева 
	void free(tree* tr); 
	//Функция уаления узла
	tree* del_elem(tree*& tr, int data);   
	//Функции поиска 
	tree* find(int data);                      
	tree* find_max();
	tree* find_min();
	//Функции добавления потмков 
	void add_left(tree* temp) { left = temp; }
	void add_right(tree* temp) { right = temp; }
	//Функция получения значения 
	int getData() { return data; }


protected:
	int data;
	//Указатели на предков 
	tree* left;
	tree* right;
	//Указатели на потомков 
	tree* parent;
	unsigned char height;
};

tree::tree()
{
	data = 0;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	height = 0;
}
tree::tree(int data)
{
	this->data = data;
	left = right = parent = nullptr;
	height = 1;
}
tree::~tree()
{
}

void tree:: Add(int data, tree*& tr)
{
	if (!tr)//Если указатель пустой 
	{
		tr = new tree;
		tr->data = data;
		tr->left = 0;
		tr->right = 0;
		return;
	}
	else 
	{
		if (tr->data > data)//Если  новый узел больше корниевого 
		{
			Add(data, tr->left);//Рекурсивный вызов функции
			tr->left->parent = tr;
		}
		else
		{
			Add(data, tr->right);//Рекурсивный вызов функции
			tr->right->parent = tr;
		}
	}
}

void tree::print_tree(int level)
{
	if (this != nullptr)//Проверка на заполненность
	{
		this->right->print_tree(level + 1);
		for (int i = 1; i < level; i++)
			cout << "    ";
		cout << this->data << endl;
		this->left->print_tree(level + 1);
	}
}
 
int tree::getHeight(tree* tr)
{
	if (tr == nullptr)
		return 0;

	return tr->height;
}
tree* tree::rotateRight(tree* y) 
{
	tree* x = y->left;
	tree* T2 = x->right;

	
	x->right = y;
	y->left = T2;

	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}
tree* tree::rotateLeft(tree* x) 
{
	tree* y = x->right;
	tree* T2 = y->left;

	
	y->left = x;
	x->right = T2;

	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	return y;
}
tree* tree::insertBT(tree* tr, int data)
{

	if (tr == nullptr)
		return new tree(data);

	
	if (data < tr->data)
		tr->left = insertBT(tr->left, data);
	else if (data > tr->data)
		tr->right = insertBT(tr->right, data);
	else
		return tr; 

	tr->height = max(getHeight(tr->left), getHeight(tr->right)) + 1;

	
	int balance = getHeight(tr->left) - getHeight(tr->right);

	if (balance > 1 && data < tr->left->data)
		return rotateRight(tr);

	if (balance < -1 && data > tr->right->data)
		return rotateLeft(tr);

	if (balance > 1 && data > tr->left->data)
	{
		tr->left = rotateLeft(tr->left);
		return rotateRight(tr);
	}

	if (balance < -1 && data < tr->right->data)
	{
		tr->right = rotateRight(tr->right);
		return rotateLeft(tr);
	}

	return tr;
}

//Функции обходов 
void tree:: pr_obh(tree* tr)
{
	if (tr == nullptr)
		return;

	cout << tr->data << " ";
	pr_obh(tr->left);
	pr_obh(tr->right);
}
void tree:: sim_obh(tree* tr)
{
	if (tr == nullptr)
		return;

	sim_obh(tr->left);
	cout << tr->data << " ";
	sim_obh(tr->right);
}
void tree:: obr_obh(tree* tr)
{
	if (tr == nullptr)
		return;

	obr_obh(tr->left);
	obr_obh(tr->right);
	cout << tr->data << " ";
}

bool tree:: is_empty(tree*& tr)
{
	if (!tr)
		return 0;
	else
		return 1;
}

void tree:: free(tree* tr)
{
	if (!tr)
		return;

	free(tr->left);
	free(tr->right);

	delete tr;
	tr = nullptr;
}
//Функции поиска 
tree* tree::find(int data)
{
	if (this == nullptr || this->data == data)
		return this;
	else if (data > this->data)
		return this->right->find(data);
	else
		return this->left->find(data);
}
tree* tree::find_max()
{
	if (this->right == nullptr)
		return this;
	return this->right->find_max();
}
tree* tree::find_min()
{
	if (this->left == nullptr)
		return this;
	return this->left->find_min();
}
//Функция удаления узла 
tree* tree::del_elem(tree*& tr, int data)
{
	if (tr == nullptr)
		return tr;

	if (data == tr->data)//Проверка на равенство с нужным узлом 
	{
		tree* tmp = nullptr;

		if (tr->left == nullptr && tr->right != nullptr)//Если нет потомков у нужного узла 
		{
			tmp = tr->right;
			delete tr;
			tr = tmp;
		}
		else if (tr->left != nullptr && tr->right == nullptr) //Если нет левого потомка у нужного узла  
		{
			tmp = tr->left;
			delete tr;
			tr = tmp;
		}
		else if (tr->left != nullptr && tr->right != nullptr) //Если нет правого потомка у нужного узла  
		{
			tmp = tr->right;

			while (tmp->left != nullptr)
				tmp = tmp->left;

			if (tmp->right == nullptr)
			{
				tr->data = tmp->data;
				if (tmp->parent->left->data >= tr->data)
					tmp->parent->left = nullptr;
				else
					tmp->parent->right = nullptr;
			}
			else
			{
				tr->data = tmp->data;
				if (tmp->parent->left->data >= tr->data)
					tmp->parent->left = tmp->right;
				else
					tmp->parent->right = tmp->right;
			}
			delete tmp;
			tmp = tr;
		}
		else
		{
			delete tr;
			tr = nullptr;
		}

		return tmp;
	}
	else if (data < tr->data)//Переход на левый узел
		tr->left = del_elem(tr->left, data);
	else
		tr->right = del_elem(tr->right, data);//Переход на правый узел

	return tr;
}


class TreePrint 
{
private:
	RenderWindow window;
	Font font;
	const int radius = 15; 
	const int hGap = 30; 
	const int vGap = 60; 

public:
	TreePrint() 
	{
		window.create(sf::VideoMode(850, 500), L"ррр");
	}

	void drawNode(tree* node, int x, int y, int level)
	{
		const Color VertexDefaultColor = Color(112, 255, 215);//Определение цвета узла
		if (node == nullptr)
			return;

		CircleShape circle(radius);
		circle.setPosition(x - radius, y - radius);
		circle.setFillColor(VertexDefaultColor);
		//circle.setFillColor(sf::Color::White);
		circle.setOutlineThickness(2.f);
		circle.setOutlineColor(sf::Color::Black);
		window.draw(circle);

		font.loadFromFile("C:/IT/ArialRegular.ttf");//Подключние шрифта

		Text text(std::to_string(node->data), font, 16);
		text.setFillColor(sf::Color::Black);
		text.setPosition(x - radius / 2.f, y - radius / 2.f);
		window.draw(text);

		if (node->left != nullptr)
		{
			int childX = x - hGap * (1 << (level - 1));
			int childY = y + vGap;
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x-0.6*radius, y + 0.9*radius), sf::Color::Black), 
				sf::Vertex(sf::Vector2f(childX, childY - 0*radius), sf::Color::Black) 
			};
			window.draw(line, 2, sf::Lines);
			drawNode(node->left, childX, childY, level - 1);
		}

		if (node->right != nullptr) 
		{
			int childX = x + hGap * (1 << (level - 1));
			int childY = y + vGap;
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x + 0.5 * radius, y + 0.8 * radius), sf::Color::Black),
				sf::Vertex(sf::Vector2f(childX, childY - radius), sf::Color::Black)
			};
			window.draw(line, 2, sf::Lines);
			drawNode(node->right, childX, childY, level - 1);
		}
	}

	void printBinaryTree(tree* root)
	{
		const Color WindowColor = Color(150,150,150);//Определение цвета фона
		window.clear(WindowColor);
		if (root != nullptr)
		{
			int x = window.getSize().x / 2;
			int y = radius * 2;
			int level = getTreeHeight(root);
			drawNode(root, x, y, level);
		}
		window.display();

		sf::Event event;
		while (window.isOpen())
		{
			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();
		}
	}
	void close()
	{
		window.close();
	}

	int getTreeHeight(tree* node) 
	{
		if (node == nullptr) 
			return 0;
		else 
		{
			int leftHeight = getTreeHeight(node->left);
			int rightHeight = getTreeHeight(node->right);
			return 1 + std::max(leftHeight, rightHeight);
		}
	}
};


int main()
{
	setlocale(0, "ru");
	int n, el;
	cout << "Введите количество узлов: ";
	cin >> n;
	tree* tr = nullptr;
	
	for (size_t i = 0; i < n; i++)
	{
		cout << "Значение узла:"; cin >> el;
		tr = tr->insertBT(tr, el);
	}
	tr->print_tree(1);
	cout << " Введите узел для поиска:";
	cin >> el;
		tree* tr2;
	tr2 = tr->find(el);
	if (tr2 != nullptr)
		cout << "Узла нет в дереве!" << endl;
	else
		cout << "Узел есть в дереве" << endl;
	cout << "Обход прямой:" << endl;
	tr->pr_obh(tr);
	cout << endl;
	cout << "Обход обратный" << endl;
	tr->obr_obh(tr);
	cout << endl;
	cout << "Обход симметричный" << endl;
	tr->sim_obh(tr);
	cout << endl;
	TreePrint printer;
	printer.printBinaryTree(tr);
	cout << "Введите узео для добавления:"; cin >> el;
	tr->Add(el, tr);
	tr->print_tree(1);
	TreePrint printer1;
	printer1.printBinaryTree(tr);
	cout << "Введите узел для удаления:"; cin >> el;
	tr->del_elem(tr, el);
	tr->print_tree(1);
	TreePrint printer2;
	printer2.printBinaryTree(tr);
	return 0;
}