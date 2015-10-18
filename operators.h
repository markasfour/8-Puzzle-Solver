#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<int> > VECTOR;

VECTOR swap(VECTOR x, int a, int b, int c, int d)
{
	int z = x.at(c).at(d);
	x.at(a).at(b) = z;
	x.at(c).at(d) = 0;
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
			if(x.at(i).at(j) == 0)
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
#endif
