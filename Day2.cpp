#include <iostream>
#include <fstream>
#include <string>
int main()
{
	std::fstream plik;
	plik.open("AoC_D2.txt");
	std::string trash, temp, data, single, number = "";
	int index = 0, real = 0, suma = 0, mred = 0, mgreen = 0, mblue = 0, suma2 = 0;;
	bool good = true;

	while (!plik.eof())
	{
		getline(plik, trash, ' ');
		getline(plik, temp, ':');
		index = stoi(temp);
		getline(plik, data);
		data += ';';

		do
		{
			single = data.substr(0, data.find(";"));
			if (single.find("red") != std::string::npos)
			{
				if (single[single.find("red") - 3] != ' ')
					number += single[single.find("red") - 3];

				number += (single[single.find("red") - 2]);
				real = stoi(number);
				number = "";
				if (real > mred)
					mred = real;
				if (real > 12)
					good = false;
			}
			if (single.find("green") != std::string::npos)
			{
				if (single[single.find("green") - 3] != ' ')
					number += single[single.find("green") - 3];

				number += (single[single.find("green") - 2]);
				real = stoi(number);
				number = "";
				if (real > mgreen)
					mgreen = real;
				if (real > 13)
					good = false;
			}
			if (single.find("blue") != std::string::npos)
			{
				if (single[single.find("blue") - 3] != ' ')
					number += single[single.find("blue") - 3];

				number += (single[single.find("blue") - 2]);
				real = stoi(number);
				number = "";
				if (real > mblue)
					mblue = real;
				if (real > 14)
					good = false;
			}

			data.erase(0, data.find(";") + 1);

		} while (data.find(";") != std::string::npos);

		if (good)
			suma += index;

		suma2 += mred * mblue * mgreen;
		mgreen = 0;
		mblue = 0;
		mred = 0;
		good = true;

	}
	std::cout << suma << " " << suma2;
	plik.close();
	return 0;
}