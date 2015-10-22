#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<int> > VECTOR;

void PRINT(VECTOR x)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << x.at(i).at(j);
		}
		cout << endl;
	}
}

//node structure
struct node
{
	VECTOR x;
	int uniform_cost;
	int heuristic_cost;
	int total;
	node *child1 = NULL;
	node *child2 = NULL;
	node *child3 = NULL;
	node *child4 = NULL;
	node *parent = NULL;
	bool goal = false;

	node(VECTOR a) //constructor
	{
		x = a;
		uniform_cost = 0;
		heuristic_cost = 0;
	};
	node(VECTOR a, int uc) //constructor
	{
		x = a;
		uniform_cost = uc;
		heuristic_cost = 0;
	};
	node(const node &a)
	{
		x = a.x;
		uniform_cost = a.uniform_cost;
		heuristic_cost = a.heuristic_cost;
		total = a.total;
		child1 = a.child1;
		child2 = a.child2;
		child3 = a.child3;
		child4 = a.child4;
		parent = a.parent;
		goal = a.goal;
	}
	void operator=(const node &a)
	{
		x = a.x;
		uniform_cost = a.uniform_cost;
		heuristic_cost = a.heuristic_cost;
		total = a.total;
		child1 = a.child1;
		child2 = a.child2;
		child3 = a.child3;
		child4 = a.child4;
		parent = a.parent;
		goal = a.goal;

	}
	void print() //prints current puzzle
	{
		PRINT(x);	
	}
};

struct compare  
{  
	bool operator()(const node& l,const node& r)  
	{  
		return l.total > r.total;  
	}  
};  

#endif
