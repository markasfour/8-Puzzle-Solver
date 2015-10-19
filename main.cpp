#include <iostream>
#include <vector>
#include <unistd.h>
#include "node.h"
#include "operators.h"
#include "heuristics.h"
using namespace std;

//search tree
vector <node> TREE; 
//visited nodes
vector <node> VISITED;
//search queue
vector <node> SEARCH;

bool already_visited (VECTOR x)
{
	for (int i = 0; i < VISITED.size(); i++)
	{
		if (VISITED.at(i).x == x)
		{
			return true;
		}
	}
	return false;
}

//make tree
void search(VECTOR problem, string h)
{
	node x(problem);

	VISITED.push_back(x);
	SEARCH.push_back(x);

	while(!SEARCH.empty())
	{
		if(SEARCH.at(0).x == GOAL)
		{
			break;
		}
		else
		{
			SEARCH.erase(SEARCH.begin());
			if(h == "")
			{
				node n1 (operator_down(x.x), x.uniform_cost + 1, 0);
				node n2 (operator_up(x.x), x.uniform_cost + 1, 0);
				node n3 (operator_left(x.x), x.uniform_cost + 1, 0);
				node n4 (operator_right(x.x), x.uniform_cost + 1, 0);
			}
			else if(h == "misplaced")
			{
				node n1 (operator_down(x.x), x.uniform_cost + 1, misplaced_h(x.x));
				node n2 (operator_up(x.x), x.uniform_cost + 1, misplaced_h(x.x));
				node n3 (operator_left(x.x), x.uniform_cost + 1, misplaced_h(x.x));
				node n4 (operator_right(x.x), x.uniform_cost + 1, misplaced_h(x.x));
			}
			else if(h == "manhattan")
			{
				node n1 (operator_down(x.x), x.uniform_cost + 1, manhattan_h(x.x));
				node n2 (operator_up(x.x), x.uniform_cost + 1, manhattan_h(x.x));
				node n3 (operator_left(x.x), x.uniform_cost + 1, manhattan_h(x.x));
				node n4 (operator_right(x.x), x.uniform_cost + 1, manhattan_h(x.x));
			}
			
			if (!already_visited(n1.x)) 
			{
				//SEARCH.push(n1); 
			}
			if (!already_visited(n2.x)) 
			{
				//SEARCH.push(n2); 
			}
			if (!already_visited(n3.x)) 
			{
				//SEARCH.push(n3); 
			}
			if (!already_visited(n4.x)) 
			{
				//SEARCH.push(n4); 
			}
		}
	}
}

void goal_check()
{
	for (int i = 0; i < TREE.size(); i++)
	{
		//if (TREE.at(i).goal)
		{
			return;
		}
	}
	TREE.clear();
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

	search(problem, "");

	return 0;
}
