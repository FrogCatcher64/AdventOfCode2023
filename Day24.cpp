#include <iostream>
#include <fstream>
#include <string>

long double ab[300][2];
long long coordinates[300][6];
std::string hailstones[300];

void FindAB(std::string line, int currenthailstone)
{
	long double a = 0, b = 0;
	std::string temp;
	int counter = 0;

	while(true)
	{
		if (counter == 6)
			break;
		if (isdigit(line[0]) || line[0] == '-')
		{
			temp += line[0];
			line.erase(0, 1);
		}
		else {
			if (isdigit(temp[0]) || temp[0] == '-') {
				coordinates[currenthailstone][counter] = stoll(temp);
				temp = "";
				counter++;
			}
			line.erase(0, 1);
		}
	}
	a = coordinates[currenthailstone][4];
	a /=  coordinates[currenthailstone][3];
	b = ((-a) * coordinates[currenthailstone][0]);
	b += coordinates[currenthailstone][1];
	ab[currenthailstone][0] = a;
	ab[currenthailstone][1] = b;
}

bool InArea(long double x, long double y)
{
	if (x >= 200000000000000 && x <= 400000000000000 && y >= 200000000000000 && y <= 400000000000000)
		return true;
	else
		return false;
}

bool InFuture (long double crossx, int i, int j)
{
	if (coordinates[i][3] >= 0) {
		if (crossx < coordinates[i][0])
			return false;
	}
	else {
		if (crossx > coordinates[i][0])
			return false;
	}
	if (coordinates[j][3] >= 0) {
		if (crossx < coordinates[j][0])
			return false;
	}
	else {
		if (crossx > coordinates[j][0])
			return false;
	}

	return true;
}

int FindCrosses(int hailstones)
{
	int answer = 0;
	long double crossx = 0, crossy = 0;
	for (int i = 0; i < hailstones-1; i++)
	{
		for (int j = i+1; j < hailstones; j++)
		{
			if (ab[i][0] != ab[j][0])
			{
				crossx = ab[j][1] - ab[i][1];
				crossx /= ab[i][0] - ab[j][0];
				crossy = (ab[i][0] * crossx) + ab[i][1];
				if (InArea(crossx, crossy) && InFuture(crossx, i, j))
				{
					answer++;
					//std::cout << coordinates[i][0] << " " << crossx << " " << coordinates[j][0] << " " << crossy << std::endl;
				}
			}
		}
	}
	return answer;
}

int main()
{
	int currenthailstone = 0;
	std::fstream file;
	file.open("Aoc_D24.txt");
	while (!file.eof())
	{
		getline(file, hailstones[currenthailstone]);
		FindAB(hailstones[currenthailstone], currenthailstone);
		currenthailstone++;
	}
	file.close();
	std::cout << FindCrosses(currenthailstone);
	return 0;
}