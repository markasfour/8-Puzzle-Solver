#ifndef HEURISTICS_H
#define HEURISTICS_H

#include <iostream>
#include <vector>
using namespace std;

//goal state for 8 puzzle
const VECTOR GOAL = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };

int misplaced_h(VECTOR x)
{
	int num = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(x.at(i).at(j) == 0) //skip the blank
			{
				continue;
			}
			if(x.at(i).at(j) != GOAL.at(i).at(j)) //check match
			{
				num++;
			}
		}
	}
	return num;
}

void find(int a, int &p, int &q)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(GOAL.at(i).at(j) == a)
			{
				p = i;
				q = j;
				return;
			}
		}
	}
}

int manhattan_h(VECTOR x)
{
	int num = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(x.at(i).at(j) == 0) //skip space
			{
				continue;
			}
			if(x.at(i).at(j) != GOAL.at(i).at(j))
			{
				int a, b;
				find(x.at(i).at(j), a, b);
				a = a - i;
				b = b - j;
				while(a != 0 && b != 0)
				{
					if(a > 0)
					{
						a--;
						num++;
					}
					if(a < 0)
					{
						a++;
						num++;
					}
					if(b > 0)
					{
						b--;
						num++;
					}
					if(b < 0)
					{
						b++;
						num++;
					}
				}
			}
		}
	}
	return num;
}

#endif