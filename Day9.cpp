#include <iostream>
#include <fstream>
#include <string>

int ChangeToTab(std::string line)
{
	int elements = std::count(line.begin(), line.end(), ' ') + 1;
	int tab[20][50] = { 0 }; // elements
	int current = 1, len = 0;
	bool allzero = false;
	long long answer = 0;
	for (int i = 0; i < elements; i++)
	{
		tab[0][i] = stoi(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);
	}
	answer += tab[0][elements - 1];

	while (!allzero)
	{
		for (int i = 0; i < elements-current; i++)
		{
			tab[current][i] = tab[current - 1][i + 1] - tab[current - 1][i];
			len = i;
		}
		
		allzero = true;
		for (int i = 0; i < len + 1; i++) {
			if (tab[current][i] != 0)
				allzero = false;
		}
		answer += tab[current][len];
		current++;
	}
	return answer;
}

int main()
{
	std::fstream file;
	std::string line;
	long long answer = 0;
	file.open("AoC_D9.txt");
	while (!file.eof())
	{
		getline(file, line);
		answer+= ChangeToTab(line);
		//std::cout << ChangeToTab(line) << " ";
	}
	file.close();
	std::cout << answer;
	return 0;
}