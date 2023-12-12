#include <iostream>
#include <fstream>
#include <string>

#define amount 140
int hashrow[500] = { 0 }, hashcolumn[500] = { 0 };

int main()
{
	int columns[amount] = { 0 }, rows[amount] = { 0 }; // 1 lub 2/1000000 w zaleznosci od ekspansji
	int hashtags = 0;
	std::string lines[amount];
	std::fstream file;
	int currentline = 0;
	bool empty = true;
	file.open("AoC_D11.txt");
	while (!file.eof())
	{
		getline(file, lines[currentline]);
		for (int i = 0; i < amount; i++) { // sprawdzanie, czy linia jest pusta
			if (lines[currentline][i] == '#') {
				hashrow[hashtags] = currentline;
				hashcolumn[hashtags] = i;
				hashtags++;
				empty = false;
			}
		}
		if (empty)
			rows[currentline] = 1000000; // 2 na part 1 
		else
			rows[currentline] = 1;

		empty = true;
		currentline++;
	}
	file.close();

	for (int i = 0; i < amount; i++) // sprawdzanie, czy kolumna jest pusta
	{
		for (int j = 0; j < amount; j++) {
			if (lines[j][i] == '#') {
				empty = false;
				break;
			}
		}
		if (empty)
			columns[i] = 1000000; // 2 na part 1 
		else
			columns[i] = 1;

		empty = true;
	}

	unsigned long long path = 0;
	int k = 0, smaller=0;
	for (int i = 0; i < hashtags - 1; i++) 
	{
		k = i + 1;
		while (k < hashtags) // obliczanie drogi dla hashtagow
		{
			if (hashcolumn[k] <= hashcolumn[i])
				smaller = hashcolumn[k];
			else
				smaller = hashcolumn[i];

			for (int j = smaller; j < abs(hashcolumn[k] - hashcolumn[i]) + smaller; j++)
				path += columns[j];

			if (hashrow[k] <= hashrow[i])
				smaller = hashrow[k];
			else
				smaller = hashrow[i];

			for (int j = smaller; j < abs(hashrow[k] - hashrow[i]) + smaller; j++)
				path += rows[j];
			
			k++;
		}
	}

	std::cout << path;
	return 0;
}