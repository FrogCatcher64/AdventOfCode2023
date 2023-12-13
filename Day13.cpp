#include <iostream>
#include <fstream>
#include <string>

int VerticalReflection(std::string line[], int lines)
{
	bool zero = false;
	int verticallines = line[0].length();
	std::string verticalline[20];
	for (int i = 0; i < verticallines; i++)
	{
		for(int j = 0; j < lines; j++) {
			verticalline[i] += line[j][i];
		}
	}

	int answer = 0;
	for (int i = 0; i < verticallines - 1; i++)
	{
		if (verticalline[i] == verticalline[i + 1]) {
			for (int j = 0; j < i && j < verticallines - i - 2; j++)
			{
				if (verticalline[i - 1 - j] != verticalline[i + 2 + j]) {
					zero = true;
					break;
				}
			}
			if (zero) {
				answer = 0;
				zero = false;
			}
			else {
				answer = i + 1;
				break;
			}
		}
	}

	return answer;
}

int HorizontalReflection(std::string line[], int lines)
{
	bool zero = false;
	int answer = 0;
	for (int i = 0; i < lines-1; i++)
	{
		if (line[i] == line[i + 1]) {
			for (int j = 0; j < i && j < lines - i - 2; j++)
			{
				if (line[i - 1 - j] != line[i + j + 2]) {
					zero = true;
					break;
				}
			}
			if (zero) {
				answer = 0;
				zero = false;
			}
			else {
				answer = i + 1;
				break;
			}
		}
	}
	return answer * 100;
}

int main()
{
	int currentline = 0, answer = 0;;
	std::string lines[20];
	std::fstream file;
	file.open("AoC_D13.txt");
	while (!file.eof())
	{
		getline(file, lines[currentline]);
		if (lines[currentline] == "")
		{
			answer += VerticalReflection(lines, currentline);
			answer += HorizontalReflection(lines, currentline);
			currentline = -1;
		}
		currentline++;
	}
	file.close();

	std::cout << answer;
	return 0;
}