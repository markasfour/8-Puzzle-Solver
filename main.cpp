#include <iostream>
#include <vector>
using namespace std;

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
		e = 5; f = 6; g = 7; h = 8;
		i = 0;
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
	
	int arr[3][3];
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = input.at(k);
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
