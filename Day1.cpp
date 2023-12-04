#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream plik;
	plik.open("AoC_D1.txt");
	std::string line, command = "", number, digit;
	std::string digits[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int sum=0, position=0;

	while (!plik.eof()) {
		getline(plik, line);
		for(int j=0; j<line.length()/3; j++) {
			for (int i = 0; i < 10; i++) 
			{
				if (line.find(digits[i]) != std::string::npos) {
					position = line.find(digits[i]);
					digit = std::to_string(i + 1);
					line[position+1] = digit[0];
				}
			}
		}
		for (int i = 0; i <= line.length(); i++){
			if (isdigit(line[i]))
				command += line[i];
		}
		number = command[0];
		number += command[command.length() - 1];
		sum += stoi(number);
		command = "";
	}
	std::cout << sum;

	plik.close();
	return 0;
}