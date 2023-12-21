#include <iostream>
#include <fstream>
#include <string>

int answer = 0;

bool OneDifference(std::string line1, std::string line2) {
    int differences = 0;

    for (int i = 0; i < line1.length(); ++i) {
        if (line1[i] != line2[i]) 
            differences++;
        if (differences > 1) 
            return false;
    }

    if (differences == 1)
        return true;
    else
        return false;
}

bool HorizontalReflection(std::string line[], int currentline, int lines, int& tolerance) {

    for (int i = currentline, j = currentline + 1; i > -1 && j < lines; --i, ++j) {

        if (!(i >= 0 && i < lines && j >= 0 && j < lines)) // poprawnosc danych
            break;
        if (line[i] != line[j]) {
            if (tolerance > 0 && OneDifference(line[i], line[j])) {
                tolerance--;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool VerticalReflection(std::string line[], int currentline, int& tolerance, int lines) 
{
    std::string verticalline[20];
    int verticallines = line[0].length();
    for (int i = 0; i < verticallines; i++)
	{
		for(int j = 0; j < lines; j++) {
			verticalline[i] += line[j][i];
		}
	}
    return HorizontalReflection(verticalline, currentline, verticallines, tolerance);
}

void AddToAnswer(std::string line[], int lines) 
{
    int tolerance = 1; // tolerancja moze wynosic maksymalnie 1, aby nowa linia mogla istniec
    for (int i = 0; i < lines - 1; i++) {
        tolerance = 1;
        if (HorizontalReflection(line, i, lines, tolerance))
        {
            if(tolerance == 0)
            {
                answer += (i + 1) * 100;
                    break;
            }
        }
    }

    for (int i = 0; i < line[0].length() - 1; i++) {
        tolerance = 1;
        if (VerticalReflection(line, i, tolerance, lines))
        {
            if (tolerance == 0) {
                answer += i + 1;
                break;
            }
        }
    }
}

int main() 
{
    std::string line[20];
    int lines = 0;

    std::fstream file;
    file.open("AoC_D13.txt");
    while (!file.eof())
    {
        getline(file, line[lines]);
        if (line[lines] == "")
        {
            AddToAnswer(line, lines);
            lines = -1;
        }

        lines++;
    }
    std::cout << answer;

    return 0;
}