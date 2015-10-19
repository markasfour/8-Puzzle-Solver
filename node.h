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
	node *child1;
	node *child2;
	node *child3;
	node *child4;
	node *parent;
	bool goal;

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
	void print() //prints current puzzle
	{
		PRINT(x);	
	}
};


#endif
