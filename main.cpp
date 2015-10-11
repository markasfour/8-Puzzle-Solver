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
	int z = x.at(c).at(d);
	x.at(a).at(b) = z;
	x.at(c).at(b) = 0;
	return x;
}

//go up. Empty space cannot be on bottom row
VECTOR operator_up(VECTOR x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x.at(2).at(i) == 0)
		{
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x.at(i).at(j) == 0)
			{
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a + 1, b);
}

//go down. Empty space cannot be on top row
VECTOR operator_down(VECTOR x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x.at(0).at(i) == 0)
		{
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x.at(i).at(j) == 0)
			{
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a - 1, b);
}

//go left. Empty space cannot be on right row
VECTOR operator_left(VECTOR x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x.at(i).at(2) == 0)
		{
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (x.at(i).at(j) == 0)
			{
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a, b + 1);
}

//go right
VECTOR operator_right(VECTOR x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x.at(i).at(0) == 0)
		{
			return x;
		}
	}
	//find 0
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (x.at(i).at(j) == 0)
			{
				a = i;
				b = j;
			}
		}
	}
	return swap(x, a, b, a, b - 1);
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
	
	VECTOR problem(3, vector<int> (3));
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			problem.at(i).at(j) = input.at(k);
			cout << problem.at(i).at(j);
			k++;
		}
		cout << endl;
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
