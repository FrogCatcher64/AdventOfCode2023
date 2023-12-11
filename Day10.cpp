#include <iostream>
#include <fstream>
#include <string>

#define amount 140
int main()
{
	std::string lines[amount];
	int linesam = 0;
	int SlocH = 0, SlocW = 0;
	int currentline = 0, currentelement = 0;
	int lastmove = 0, moves = 1;
	char currentpipe = 'S';
	bool zong = false, loopSouth = false;

	std::fstream file;
	file.open("AoC_D10.txt");
	while (!file.eof()) {
		getline(file, lines[linesam]);
		for (int i = 0; i < amount; i++) { // szukanie lokalizacji S
			if (lines[linesam][i] == 'S') {
				SlocH = linesam;
				SlocW = i;
			}
		}
		linesam++;
	}

	if (lines[SlocH][SlocW + 1] == '-' || lines[SlocH][SlocW + 1] == '7') {
		currentline = SlocH;
		currentelement = SlocW + 1;
		lastmove = 1;
	}
	else if (lines[SlocH + 1][SlocW] == 'L' || lines[SlocH + 1][SlocW] == 'J' || lines[SlocH + 1][SlocW] == '|') {
		currentline = SlocH + 1;
		currentelement = SlocW;
		lastmove = -2;
	}
	else if (lines[SlocH][SlocW - 1] == '-' || lines[SlocH][SlocW - 1] == 'L' || lines[SlocH][SlocW - 1] == 'F') {
		currentline = SlocH;
		currentelement = SlocW - 1;
		lastmove = -1;
	}
	// 1 - prawo, -1 - lewo, 2 - gora, -2 - dol

	while (!zong)
	{
		currentpipe = lines[currentline][currentelement];
		moves++;
		if (currentpipe == '|')
		{
			lines[currentline][currentelement] = '1';
			if (lastmove == 2) {
				currentline--;
				lastmove = 2;
			}
			else if (lastmove == -2) {
				currentline++;
				lastmove = -2;
			}
			else
				zong = true;
		}
		else if (currentpipe == '-')
		{
			lines[currentline][currentelement] = '0';
			if (lastmove == 1) {
				currentelement++;
				lastmove = 1;
			}
			else if (lastmove == -1) {
				currentelement--;
				lastmove = -1;
			}
			else
				zong = true;
		}
		else if (currentpipe == 'L')
		{
			lines[currentline][currentelement] = '0';
			if (lastmove == -2) {
				currentelement++;
				lastmove = 1;
			}
			else if (lastmove == -1) {
				currentline--;
				lastmove = 2;
			}
			else
				zong = true;
		}
		else if (currentpipe == 'J')
		{
			lines[currentline][currentelement] = '0';
			if (lastmove == -2) {
				currentelement--;
				lastmove = -1;
			}
			else if (lastmove == 1) {
				currentline--;
				lastmove = 2;
			}
			else
				zong = true;
		}
		else if (currentpipe == '7')
		{
			lines[currentline][currentelement] = '1';
			if (lastmove == 1) {
				currentline++;
				lastmove = -2;
			}
			else if (lastmove == 2) {
				currentelement--;
				lastmove = -1;
			}
			else
				zong = true;
		}
		else if (currentpipe == 'F')
		{
			lines[currentline][currentelement] = '1';
			if (lastmove == -1) {
				currentline++;
				lastmove = -2;
			}
			else if (lastmove == 2) {
				currentelement++;
				lastmove = 1;
			}
			else
				zong = true;
		}
		else if (currentpipe == '.') { // koniec zabawy 
			zong = true;
		}
		else if (currentpipe == 'S') {
			lines[SlocH][SlocW] = '1';
			zong = true;
		}
	}

	int answer = 0;
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			if (lines[i][j] == '1')
			{
				if (loopSouth)
					loopSouth = false;
				else
					loopSouth = true;
			}
			else if (lines[i][j] != '0' && loopSouth == true)
				answer++;
		}
	}

	std::cout << moves / 2 << " " << answer;

	return 0;
}