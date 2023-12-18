#include <iostream>
#include <fstream>
#include <string>

void TurlajKamieniaPolnoc(std::string line[], int lines, int currentelement)
{
	for (int i = lines; i > 0; i--)
	{
		if (line[i - 1][currentelement] == '.')
			std::swap(line[i][currentelement], line[i - 1][currentelement]);
		else
			break;
	}
}
void TurlajKamieniaZachod(std::string line[], int lines, int currentelement)
{
	for (int i = currentelement; i > 0; i--)
	{
		if (line[lines][i-1] == '.')
			std::swap(line[lines][i], line[lines][i-1]);
		else
			break;
	}
}

void TurlajKamieniaPoludnie(std::string line[], int lines, int currentelement)
{
	for (int i = lines; i < 99; i++)
	{
		if (line[i + 1][currentelement] == '.')
			std::swap(line[i][currentelement], line[i + 1][currentelement]);
		else
			break;
	}
}

void TurlajKamieniaWschod(std::string line[], int lines, int currentelement)
{
	for (int i = currentelement; i < line[0].length()-1; i++)
	{
		if (line[lines][i + 1] == '.')
			std::swap(line[lines][i], line[lines][i + 1]);
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
		currentline++;
	}
	file.close();

	for(int c = 0; c< 300; c++)
	{
		std::cout << c << "/300" << std::endl;
		for (int j = 1; j < 100; j++) {
			for (int i = 0; i < line[0].length(); i++) {
				if (line[j][i] == 'O') {
					TurlajKamieniaPolnoc(line, j, i);
				}
			}
		}
		for (int j = 0; j < 100; j++) {
			for (int i = 1; i < line[0].length(); i++) {
				if (line[j][i] == 'O') {
					TurlajKamieniaZachod(line, j, i);
				}
			}
		}
		for (int j = 98; j >= 0; j--) {
			for (int i = 0; i < line[0].length(); i++) {
				if (line[j][i] == 'O') {
					TurlajKamieniaPoludnie(line, j, i);
				}
			}
		}
		for (int j = 0; j < 100; j++) {
			for (int i = 98; i >= 0; i--) {
				if (line[j][i] == 'O') {
					TurlajKamieniaWschod(line, j, i);
				}
			}
		}
		currentline = 100;
		for (int i = 0; i < 100; i++)
		{
			sum += AddToSum(line[i], currentline);
			currentline--;
		}
		std::cout << sum << std::endl;
		sum = 0;
	}

	return 0;
}