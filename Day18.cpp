#include <iostream>
#include <fstream>
#include <string>

int lagoon[370][700] = { 0 };

void Draw(char direction, int move, int* x, int* y)
{
	int tomovex = *x, tomovey = *y;
	if (direction == 'U')
	{
		for (int i = 1; i <= move; i++)
		{
			*x = tomovex + i;
			lagoon[*x][*y] = 1;
		}
	}
	else if (direction == 'D')
	{
		for (int i = 1; i <= move; i++)
		{
			*x = tomovex - i;
			lagoon[*x][*y] = 1;
		}
	}
	else if (direction == 'R')
	{
		for (int i = 1; i <= move; i++)
		{
			*y = tomovey + i;
			lagoon[*x][*y] = 1;
		}
	}
	else if (direction == 'L')
	{
		for (int i = 1; i <= move; i++)
		{
			*y = tomovey - i;
			lagoon[*x][*y] = 1;
		}
	}
}

int main()
{
	std::string line, move="";
	int currentchar, movement=0;
	bool paint = false;
	int x = 120, y = 150;
	int answer = 0;
	char direction;
	std::fstream file;
	file.open("AoC_D18.txt");
	while (!file.eof())
	{
		getline(file, line);
		direction = line[0];
		currentchar = 2;
		while (isdigit(line[currentchar]))
		{
			move += line[currentchar];
			currentchar++;
		}
		movement = stoi(move);
		move = "";
		Draw(direction, movement, &x, &y);
	}
	file.close();

	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 700; j++)
		{
			if (lagoon[i][j] == 1 && lagoon[i+1][j] == 1)
				paint = !paint;

			if (paint)
				lagoon[i][j] = 1;
			
			answer += lagoon[i][j];
			std::cout << lagoon[i][j];
		}
		paint = false;
		std::cout << std::endl;
	}
	std::cout << answer;
	return 0;
}