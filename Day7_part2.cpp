#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define games 1000

std::vector<std::string> Five, Four, Full, Three, Two, One, High;

void CheckAndAssign(std::string line)
{
	int temp = 0, max = 0, max2 = 1, temp2=0;
	char maxsymbol='0';
	std::string hand;

	for (int i = 0; i < 5; i++)
	{
		if (line[i] == 'A')
			line[i] = 'E';
		else if (line[i] == 'K')
			line[i] = 'D';
		else if (line[i] == 'Q')
			line[i] = 'C';
		else if (line[i] == 'J')
			line[i] = '1';
		else if (line[i] == 'T')
			line[i] = 'A';
	}
	hand = line.substr(0, 5);

	for (int i = 0; i < 5; i++)
	{
		//checking
		temp = std::count(hand.begin(), hand.end(), hand[i]);
		if (temp > max && hand[i]!='1') {
			max = temp;
			maxsymbol = hand[i];
		}
	}
	for (int i = 0; i < 5; i++) {
		temp = std::count(hand.begin(), hand.end(), hand[i]);
		if (temp > max2 && hand[i] != maxsymbol && hand[i]!='1')
			max2 = temp;
	}
	temp2 = std::count(hand.begin(), hand.end(), '1');
	max += temp2;

	//assigning
	if (max == 5)
		Five.push_back(line);
	else if (max == 4)
		Four.push_back(line);
	else if (max == 3 && max2 == 2)
		Full.push_back(line);
	else if (max == 3)
		Three.push_back(line);
	else if (max == 2 && max2 == 2)
		Two.push_back(line);
	else if (max == 2)
		One.push_back(line);
	else
		High.push_back(line);
}

void SortData(std::vector<std::string>& category)
{
	std::string temp;
	int pom = category.size(), min = 0;
	for (int i = 0; i < pom - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < pom; j++) {
			if (category[j] < category[min])
				min = j;
		}
		if (category[i].substr(0, 5) != category[min].substr(0, 5))
		{
			temp = category[min];
			category[min] = category[i];
			category[i] = temp;
		}
	}
}

void AddPoints(int* rank, std::vector<std::string> category, long long* points)
{
	int pom = category.size();
	int bid = 0;
	for (int i = 0; i < pom; i++)
	{
		*rank = *rank + 1;
		bid = stoi(category[i].substr(6, category[i].length() - 6));
		*points += *rank * bid;
	}
}

int main()
{
	std::fstream file;
	std::string lines[games];
	int pom = 0;
	file.open("AoC_D7.txt");

	while (!file.eof()) {
		getline(file, lines[pom]);
		pom++;
	}
	file.close();

	for (int i = 0; i < pom; i++) {
		CheckAndAssign(lines[i]);
	}

	SortData(Five);
	SortData(Four);
	SortData(Full);
	SortData(Three);
	SortData(Two);
	SortData(One);
	SortData(High);

	int rank = 0;
	long long points = 0;
	AddPoints(&rank, High, &points);
	AddPoints(&rank, One, &points);
	AddPoints(&rank, Two, &points);
	AddPoints(&rank, Three, &points);
	AddPoints(&rank, Full, &points);
	AddPoints(&rank, Four, &points);
	AddPoints(&rank, Five, &points);

	std::cout << points;

	return 0;
}