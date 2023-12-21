#include <iostream>
#include <fstream>
#include <string>

std::string command[600], workflow[600];
char state = '0';

bool Check(int letter, std::string condition, std::string* currentcommand)
{
	if (letter > stoi(condition.substr(2, condition.find(':') - 2)))
	{
		*currentcommand = condition.substr(condition.find(':') + 1, condition.length() - condition.find(':') - 1);
		if (*currentcommand == "A")
			state = 'A';
		else if (*currentcommand == "R")
			state = 'R';
		else {
			return false;
		}
	}
}
bool CheckLeft(int letter, std::string condition, std::string* currentcommand)
{
	if (letter < stoi(condition.substr(2, condition.find(':') - 2)))
	{
		*currentcommand = condition.substr(condition.find(':') + 1, condition.length() - condition.find(':') - 1);
		if (*currentcommand == "A")
			state = 'A';
		else if (*currentcommand == "R")
			state = 'R';
		else {
			return false;
		}
	}
}

void Accepted(std::string* currentworkflow, int x, int m, int a, int s)
{
	bool accept = false;
	int wfindex = 0;
	std::string condition, currentcommand;
	while (true)
	{
		if (workflow[wfindex] == *currentworkflow)
			break;

		wfindex++;
	}

	currentcommand = command[wfindex];
	while (currentcommand.find(',') != -1)
	{
		condition = currentcommand.substr(0, currentcommand.find(','));
		currentcommand.erase(0, currentcommand.find(',') + 1);
		if (condition[0] == 'x')
		{
			if (condition[1] == '>') {
				if (!Check(x, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
			else {
				if (!CheckLeft(x, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}

		}
		else if (condition[0] == 'm')
		{
			if (condition[1] == '>') {
				if (!Check(m, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
			else {
				if (!CheckLeft(m, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
		}
		else if (condition[0] == 'a')
		{
			if (condition[1] == '>') {
				if (!Check(a, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
			else {
				if (!CheckLeft(a, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
		}
		else if (condition[0] == 's')
		{
			if (condition[1] == '>') {
				if (!Check(s, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
			else {
				if (!CheckLeft(s, condition, &currentcommand)) {
					*currentworkflow = currentcommand;
					return;
				}
			}
		}
		
	}
	if (currentcommand == "A")
		state = 'A';
	else if (currentcommand == "R")
		state = 'R';
	else
		*currentworkflow = currentcommand;
}

int main()
{
	long long sum = 0;
	int currentline = 0, commands = 0;
	std::string numbers[600], currentworkflow = "in";
	std::fstream file;
	file.open("AoC_D19.txt");
	while(true)
	{
		getline(file, command[currentline]);
		if (command[currentline] == "")
			break;

		workflow[currentline] = command[currentline].substr(0, command[currentline].find('{'));
		command[currentline].erase(0, command[currentline].find('{') + 1);
		command[currentline] = command[currentline].substr(0, command[currentline].length() - 1);
		currentline++;
	}
	commands = currentline - 1;
	
	int x = 0, m = 0, a = 0, s = 0;
	currentline = 0;
	while (!file.eof())
	{
		getline(file, numbers[currentline]);
		x = stoi(numbers[currentline].substr(3, numbers[currentline].find(',')-3));
		numbers[currentline].erase(0, numbers[currentline].find(',')+1);
		m = stoi(numbers[currentline].substr(2, numbers[currentline].find(',')-2));
		numbers[currentline].erase(0, numbers[currentline].find(',')+1);
		a = stoi(numbers[currentline].substr(2, numbers[currentline].find(',')-2));
		numbers[currentline].erase(0, numbers[currentline].find(',')+1);
		s = stoi(numbers[currentline].substr(2, numbers[currentline].find('}') - 2));
		while (state == '0')
			Accepted(&currentworkflow, x, m, a, s);

		if(state == 'A')
			sum += x + m + a + s;

		state = '0';
		currentworkflow = "in";
		currentline++;
	}
	std::cout << sum;
	return 0;
}