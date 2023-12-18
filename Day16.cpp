#include <iostream>
#include <fstream> 
#include <string>

int energized[110][110] = { 0 };

void SaveEnergizedData(int x, int y)
{
	energized[y][x] = 1;
}

void Beam(int posx, int posy, char dir, std::string lines[], int steps)
{
	while (true)
	{
		if (energized[posy][posx] == 1)
			steps++;
		else
			steps = 0;
		SaveEnergizedData(posx, posy);

		if (lines[posy][posx] == '/')
		{
			if (dir == 'R')
				dir = 'U';
			else if (dir == 'L')
				dir = 'D';
			else if (dir == 'D')
				dir = 'L';
			else if (dir == 'U')
				dir = 'R';
		}
		else if (lines[posy][posx] == '\\')
		{
			if (dir == 'R')
				dir = 'D';
			else if (dir == 'L')
				dir = 'U';
			else if (dir == 'D')
				dir = 'R';
			else if (dir == 'U')
				dir = 'L';
		}
		else if (lines[posy][posx] == '|')
		{
			if (dir == 'R' || dir == 'L')
			{
				Beam(posx, posy, 'U',  lines, steps);
				dir = 'D';
			}
		}
		else if (lines[posy][posx] == '-')
		{
			if (dir == 'U' || dir == 'D')
			{
				Beam(posx, posy, 'L', lines, steps);
				dir = 'R';
			}
		}

		if (dir == 'R')
			posx++;
		else if (dir == 'L')
			posx--;
		else if (dir == 'D')
			posy++;
		else if (dir == 'U')
			posy--;

		if (posy < 0 || posy > 109 || posx < 0 || posx > 109 || steps >= 12)
			break;
	}
}

int Energized()
{
	int sum = 0;
	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			if (energized[i][j] == 1)
				sum++;
			energized[i][j] = 0;
		}
	}
	return sum;
}

int main()
{
	std::string lines[110];
	int currentline = 0;
	std::fstream file;
	file.open("AoC_D16.txt");
	while (!file.eof())
	{
		getline(file, lines[currentline]);
		currentline++;
	}
	file.close();

	Beam(0, 0, 'R', lines, 0);
	std::cout << Energized() << " ";

	int temp = 0, max = 0;
	
	for (int j = 0; j < currentline; j++)
	{
		Beam(0, j, 'R', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(0, j, 'U', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(0, j, 'D', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;
	}
	for (int j = 0; j < currentline; j++)
	{
		Beam(109, j, 'L', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(109, j, 'U', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(109, j, 'D', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;
	}
	for (int j = 0; j < currentline; j++)
	{
		Beam(j, 0, 'R', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(j, 0, 'D', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(j, 0, 'L', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;
	}
	for (int j = 0; j < currentline; j++)
	{
		Beam(j, 109, 'R', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(j, 109, 'U', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;

		Beam(j, 109, 'L', lines, 0);
		temp = Energized();
		if (temp > max)
			max = temp;
	}
	std::cout << max;
	return 0;
}