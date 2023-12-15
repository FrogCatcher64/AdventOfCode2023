#include <iostream>
#include <fstream>
#include <string>

int HASH(std::string label)
{
	int value = 0;
	for (int i = 0; i < label.length(); i++) {
		value += label[i];
		value *= 17;
		value = value % 256;
	}
	return value;
}

void AddTo(std::string label, std::string focal, std::string boxes[256][40], std::string focals[256][40], int boxnumber)
{
	int current = 0;
	bool added = false;
	while (boxes[boxnumber][current] != "")
	{
		if (boxes[boxnumber][current] == label) 
		{
			boxes[boxnumber][current] = label;
			focals[boxnumber][current] = focal;
			added = true;
		}
		current++;
	}
	if (!added) {
		boxes[boxnumber][current] = label;
		focals[boxnumber][current] = focal;
	}
}

void Dash(std::string label, std::string focal, std::string boxes[256][40], std::string focals[256][40], int boxnumber)
{
	int current = 0;
	while (boxes[boxnumber][current] != "")
	{
		if (boxes[boxnumber][current] == label) {
			while (boxes[boxnumber][current] != "")
			{
				boxes[boxnumber][current] = boxes[boxnumber][current + 1];
				focals[boxnumber][current] = focals[boxnumber][current + 1];
				current++;
			}
			break;
		}
		current++;
	}
}

int main()
{
	int sum = 0, boxnumber = 0;
	bool lastone = false;
	std::string line, sequence, label, focal;
	std::string boxes[256][40], focals[256][40];
	bool equalsign = false;
	std::fstream file;
	file.open("AoC_D15.txt");
	getline(file, line);
	file.close();

	while (!lastone)
	{
		if (line.find(',') != -1) {
			sequence = line.substr(0, line.find(','));
			line.erase(0, line.find(',') + 1);
		}
		else {
			lastone = true;
			sequence = line;
		}
		
		label = "";
		for (int i = 0; i < sequence.length(); i++)
		{
			if (sequence[i] == '=') {
				equalsign = true;
				focal = sequence[i + 1];
				break;
			}
			else if (sequence[i] == '-') {
				equalsign = false;
				focal = "0";
				break;
			}
			label += sequence[i];
		}
		boxnumber = HASH(label);
		if (equalsign)
			AddTo(label, focal, boxes, focals, boxnumber);
		else
			Dash(label, focal, boxes, focals, boxnumber);
	}

	//Zliczanie punktow
	int current = 0;
	for (int i = 0; i < 256; i++)
	{
		while (boxes[i][current] != "") 
		{
			sum += (i + 1) * (current + 1) * stoi(focals[i][current]);
			current++;
		}
		current = 0;
	}

	std::cout << sum;
	return 0;
}