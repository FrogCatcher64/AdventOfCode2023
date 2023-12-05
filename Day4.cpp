#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream plik;
	plik.open("AoC_D4.txt");
	int const amount = 211;
	std::string trash, left, right, lnumbers[10];
	int sum=0, actual = 0, cards[amount]={0}, current = 0, sum2 = 0;
	for (int i = 0; i < amount; i++) {
		cards[i] = 1;
	}

	while (!plik.eof())
	{
		getline(plik, trash, ':');
		getline(plik, left, '|');
		getline(plik, right);

		for (int i = 0; i < left.length()/3; i++) { //zapisanie lewych wartosci
			lnumbers[i] = left.substr(i * 3, 3);
		}
		for (int i = 0; i < 10; i++) { // pasujace karty
			if (right.find(lnumbers[i]) != std::string::npos)
				actual++;
		}
		if(actual>0)
			sum += pow(2, actual-1); // aktualizacja sumy

		for (int i = 0; i < actual; i++) { // zmiana ilosci kart
			if(current+i+1<amount)
				cards[current + i + 1] += cards[current];
		}
		actual = 0;
		current++;
	}

	for (int i = 0; i < amount; i++) { // aktualizacja sumy2
		sum2 += cards[i];
	}
	std::cout << sum << " " << sum2;
	return 0;
}
