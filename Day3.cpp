#include <iostream>
#include <fstream>
#include <string>

void FandR(int w1, int w2, std::string lines[], int* sum, int i)
{
	std::string number;
	int first = 0;
	for (int k = -1; k >= -2; k--)
	{
		if (w2 + k >= 0 && w2 + k <= i && (lines[w1][w2 + k] >= '0' && lines[w1][w2 + k] <= '9'))
			first = k;
		else
			break;
	}
	for (int s = 0; s < 5; s++)
	{
		if ((w2 + first + s >= 0) && (w2 + first + s <= i) && lines[w1][w2 + first + s] >= '0' && lines[w1][w2 + first + s] <= '9')
		{
			number += lines[w1][w2 + first + s];
			lines[w1][w2 + first + s] = '.';
		}
		else
			break;
	}
	*sum += stoi(number);
	number = "";
}

int main()
{
	std::fstream plik;
	plik.open("AoC_D3.txt");
	std::string lines[140];
	int i = 0, character = 0, sum = 0;

	while (!plik.eof()) {
		getline(plik, lines[i]);
		i++;
	}

	for (int j = 1; j < i-1; j++) //dla kazdej linii
	{
		while (character <= i-1) // dla kazdego znaku w linii
		{
			if ((lines[j][character] > '9' || lines[j][character] < '0') && lines[j][character] != '.') // aktualny znak w linii to znak
			{
				if (character-1 >=0 && character-1 <=i && lines[j - 1][character - 1] >= '0' && lines[j - 1][character - 1] <= '9') //lewy gorny to cyfra
					FandR((j - 1), (character - 1), lines, &sum, i);

				if (character >= 0 && character <= i && lines[j - 1][character] >= '0' && lines[j - 1][character] <= '9') // gorny srodkowy to cyfra
					FandR(j - 1, character, lines, &sum, i);

				if (character + 1 >= 0 && character + 1 <= i && lines[j - 1][character + 1] >= '0' && lines[j - 1][character + 1] <= '9') //  prawy gorny srodkowy to cyfra
					FandR(j - 1, character + 1, lines, &sum, i);

				if (character - 1 >= 0 && character - 1 <= i && lines[j][character - 1] >= '0' && lines[j][character - 1] <= '9') // lewy srodkowy to cyfra
					FandR(j, character - 1, lines, &sum, i);

				if (character + 1 >= 0 && character + 1 <= i && lines[j][character + 1] >= '0' && lines[j][character + 1] <= '9') // parwy srodkowy to cyfra
					FandR(j, character + 1, lines, &sum, i);

				if (character - 1 >= 0 && character - 1 <= i && lines[j + 1][character - 1] >= '0' && lines[j + 1][character - 1] <= '9') // lewy dolny to cyfra
					FandR(j + 1, character - 1, lines, &sum, i);

				if (character >= 0 && character <= i && lines[j + 1][character] >= '0' && lines[j + 1][character] <= '9') // srodkowy dolny to cyfra
					FandR(j + 1, character, lines, &sum, i);

				if (character + 1 >= 0 && character + 1 <= i && lines[j + 1][character + 1] >= '0' && lines[j + 1][character + 1] <= '9') // prawy dolny to cyfra
					FandR(j + 1, character + 1, lines, &sum, i);

				character++;
			}
			else
				character++;
		}
		character = 0;
	}
	std::cout << sum;
	plik.close();
	return 0;
}