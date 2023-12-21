#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string line, move = "", dir="";
	int movement = 0;
	long long points_X[800] = { 0 }, points_Y[800] = { 0 };
	long long currentX = 0, currentY = 0, point = 0;
	int circuit = 0;
	unsigned long long answer = 0;
	char direction = 'R';


	std::fstream file;
	file.open("AoC_D18.txt");

	points_X[point] = currentX;
	points_Y[point] = currentY;
	point++;

	while (!file.eof())
	{
		getline(file, line);
		move = line.substr(line.find('#') + 1, 5);
		dir = line.substr(line.find('#') + 6, 1);
		movement = stoi(move, 0, 16);
		circuit += movement;
		if (dir == "0")
			currentX += movement;
		else if (dir == "1")
			currentY -= movement;
		else if (dir == "2")
			currentX -= movement;
		else if (dir == "3")
			currentY += movement;

		points_X[point] = currentX;
		points_Y[point] = currentY;
		point++;

	}
	file.close();

	long long left = 0, right = 0;
	long long Area = 0;
	for (int i = 0; i < point - 2; i++) // sznurowadlo
	{
		left = points_X[i] * points_Y[i + 1];
		right = points_X[i + 1] * points_Y[i];
		Area += left - right;
	}
	left = points_X[point - 2] * points_Y[0];
	right = points_X[0] * points_Y[point - 2];
	Area += left - right;
	Area = abs(Area);
	Area /= 2;
	answer = circuit;
	circuit /= 2;
	long long W = Area - circuit + 1; // Pick
	answer += W;
	std::cout << Area << " " << answer;
	return 0;
}