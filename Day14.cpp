#include <iostream>
#include <fstream>
#include <string>

void TurlajKamienia(std::string line[], int lines, int currentelement)
{
	for (int i = lines; i > 0; i--)
	{
		if (line[i-1][currentelement] == '.')
			std::swap(line[i][currentelement], line[i - 1][currentelement]);
		else
			break;
	}
}

int AddToSum(std::string line, int currentline)
{
	int sum = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == 'O')
			sum += currentline;
	}
	return sum;
}

int main()
{
	int currentline = 1, sum = 0;
	std::string line[100];
	std::fstream file;
	file.open("AoC_D14.txt");
	getline(file, line[0]);
	while (!file.eof())
	{
		getline(file, line[currentline]);
		for (int i = 0; i < line[currentline].length(); i++)
		{
			if(line[currentline][i] == 'O')
				TurlajKamienia(line, currentline, i);
		}
		currentline++;
	}
	file.close();

	currentline = 100;
	for (int i = 0; i < 100; i++)
	{
		std::cout << line[i] << std::endl;
		sum += AddToSum(line[i], currentline);
		currentline--;
	}
	std::cout << sum;
	return 0;
}