#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
#include "node.h"
#include "operators.h"
#include "heuristics.h"
#include "mergesort.h"
using namespace std;

//search tree
vector <node> TREE; 
//visited nodes
vector <node> VISITED;
//search queue
priority_queue <node, vector<node>, compare> SEARCH;

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
	SEARCH.push(x);

	while (!SEARCH.empty())
	{
		node curr = SEARCH.top(); 
		if (SEARCH.top().x == GOAL)
		{
			cout << "GOAL" << endl;
			break;
		}
		else
		{
			VISITED.push_back(SEARCH.top());
			SEARCH.pop();
						
			node n1 (operator_down(curr.x), curr.uniform_cost + 1);
			node n2 (operator_up(curr.x), curr.uniform_cost + 1);
			node n3 (operator_left(curr.x), curr.uniform_cost + 1);
			node n4 (operator_right(curr.x), curr.uniform_cost + 1);
			
			if (h != "")
			{
				if (h == "misplaced")
				{
					n1.heuristic_cost = misplaced_h(n1.x);
					n2.heuristic_cost = misplaced_h(n2.x);
					n3.heuristic_cost = misplaced_h(n3.x);
					n4.heuristic_cost = misplaced_h(n4.x);
				}
				if (h == "manhattan")
				{
					n1.heuristic_cost = manhattan_h(n1.x);
					n2.heuristic_cost = manhattan_h(n2.x);
					n3.heuristic_cost = manhattan_h(n3.x);
					n4.heuristic_cost = manhattan_h(n4.x);
				}
			}

			n1.total = n1.uniform_cost + n1.heuristic_cost;
			n2.total = n2.uniform_cost + n2.heuristic_cost;
			n3.total = n3.uniform_cost + n3.heuristic_cost;
			n4.total = n4.uniform_cost + n4.heuristic_cost;

			if (!already_visited(n1.x)) 
			{
				curr.child1 = &n1;
				n1.parent = &curr;
				SEARCH.push(n1); 
			}
			if (!already_visited(n2.x)) 
			{
				curr.child2 = &n2;
				n2.parent = &curr;
				SEARCH.push(n2); 
			}
			if (!already_visited(n3.x)) 
			{
				curr.child3 = &n3;
				n3.parent = &curr;
				SEARCH.push(n3); 
			}
			if (!already_visited(n4.x)) 
			{
				n4.child4 = &n4;
				n4.parent = &curr;
				SEARCH.push(n4); 
			}
		}
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
	string H;
	if (entry == 1) {H = "";}
	if (entry == 2) {H = "misplaced";}
	if (entry == 3) {H = "manhattan";}

	search(problem, H);

	return 0;
}
