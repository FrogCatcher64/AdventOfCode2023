#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> pathlenght;

void FindPath(int nextmove, std::string lines[], int x, int y, int moves) // nextmove (-1 - gora, 1 - dol, 2 - prawo, -2 - lewo
{
	int prevx = 0, prevy = 0;
	bool wentsomewhere = false;
	while (true)
	{
		prevx = x, prevy = y;
		if (nextmove == 1 || nextmove == -1)
			y += nextmove;
		else if (nextmove == -2)
			x += nextmove + 1;
		else
			x += nextmove - 1;

		moves++;
		if (y == 140)
			break;

		if (lines[y][x + 1] == '.' && x + 1 != prevx)
			nextmove = 2;
		else if (lines[y][x - 1] == '.' && x - 1 != prevx)
			nextmove = -2;
		else if (lines[y + 1][x] == '.' && y + 1 != prevy)
			nextmove = 1;
		else if (lines[y - 1][x] == '.' && y - 1 != prevy)
			nextmove = -1;
		if (lines[y][x + 1] == '>') {
			nextmove = 2;
			FindPath(nextmove, lines, x, y, moves);
			wentsomewhere = true;
		}
		if (lines[y][x - 1] == '<') {
			nextmove = -2;
			FindPath(nextmove, lines, x, y, moves);
			wentsomewhere = true;
		}
		if (lines[y + 1][x] == 'v') {
			nextmove = 1;
			FindPath(nextmove, lines, x, y, moves);
			wentsomewhere = true;
		}
		if (lines[y - 1][x] == '^') {
			nextmove = -1;
			FindPath(nextmove, lines, x, y, moves);
			wentsomewhere = true;
		}
		if (wentsomewhere)
			return;
	}
	pathlenght.push_back(moves);
}

int main()
{
	std::string lines[141];
	int currentline = 0, longest = 0;
	std::fstream file;
	file.open("AoC_D23.txt");
	while (!file.eof())
	{
		getline(file, lines[currentline]);
		currentline++;
	}
	file.close();

	FindPath(1, lines, 1, 0, 0);
	for (int i = 0; i < pathlenght.size(); i++)
	{
		if (pathlenght[i] > longest)
			longest = pathlenght[i];
	}

	std::cout << longest;
	return 0;
}