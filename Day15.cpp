#include <iostream>
#include <fstream>
#include <string>

int HASH(std::string line)
{
	int value = 0;
	for (int i = 0; i < line.length(); i++)
	{
		value += line[i];
		value *= 17;
		value = value % 256;
	}
	return value;
}

int main()
{
	int currentvalue = 0, sum = 0;
	std::string line, sequence;
	std::fstream file;
	file.open("AoC_D15.txt");
	getline(file, line);
	file.close();

	while(line.find(',') != -1)
	{
		sequence = line.substr(0, line.find(','));
		line.erase(0, line.find(',') + 1);
		sum += HASH(sequence);
	}
	sum += HASH(line);

	std::cout << sum;
	return 0;
}