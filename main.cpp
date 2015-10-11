#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef vector < vector<int> > VECTOR;

//goal state for 8 puzzle
const VECTOR GOAL = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };

//node structure
struct node
{
	VECTOR x;
	int uniform_cost;
	int heuristic_cost;
	bool goal;
	node* child1;
	node* child2; 
	node* child3;

	node(VECTOR a) {x = a;};
};

//search tree
list <node> tree;

VECTOR swap(VECTOR x, int a, int b, int c, int d)
{
	
}

//go up
VECTOR operator_up(VECTOR x)
{
		
}

//go down
VECTOR operator_down(VECTOR x)
{
	
}

//go left
VECTOR operator_left(VECTOR x)
{
	
}

//go right
VECTOR operator_right(VECTOR x)
{
	
}

//make tree
list <node> make_tree (VECTOR x)
{
	if (x == GOAL)
	{
		//return;
	}
}

//general searching algorithm 
bool GENERAL_SEARCH(VECTOR x, list <node> (*QUEUING)())
{
	list <node> tree; 
	
	if (tree.empty())
	{
		cout << "There is no solution";
		return false;
	}

	while (true)
	{
		
	}
}

//main function containing UI
int main()
{
	cout << "Welcome to Mark Asfour's 8-puzzle solver." << endl;
	cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
	int entry = 0;
	while (entry != 1 && entry != 2)
	{
		cin >> entry;
	}
	int a, b, c, d, e, f, g, h, i;
	if (entry == 1)
	{
		a = 1; b = 2; c = 3; d = 4;
		e = 5; f = 6; g = 7; h = 0;
		i = 8;
	}
	else
	{
		cout << "Enter your puzzle, use 0 to represent the blank" << endl;
		cout << "Enter the first row, separate numbers by hitting enter" << endl;
		cin >> a >> b >> c;
		cout << "Enter the second row, separate numbers by hitting enter" << endl;
		cin >> d >> e >> f;
		cout << "Enter the third row, separate numbers by hitting enter" << endl;
		cin >> g >> h >> i;
	}
	cout << a << b << c << endl;
	cout << d << e << f << endl;
	cout << g << h << i << endl;
	vector <int> input;
	input.push_back(a); input.push_back(b); input.push_back(c);
	input.push_back(d); input.push_back(e); input.push_back(f);
	input.push_back(g); input.push_back(h); input.push_back(i);
	
	cout << "HI" << endl;
	VECTOR problem(3, vector<int> (3));
	cout << problem.at(0).at(0) << endl;
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << i << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << j << endl;
			problem.at(i).at(j) = input.at(k);
			cout << problem.at(i).at(j) << endl;
			k++;
		}
	}
	
	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic." << endl;
	cout << "3. A* with the Manhattan distance heuristic." << endl;
	entry = 0;
	while (entry != 1 && entry != 2 && entry != 3)
	{
		cin >> entry;
	}

	return 0;
}
