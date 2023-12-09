#include <iostream>
#include <fstream>
#include <string>

#define amount 798
int main()
{
	std::string temp, LR, node[amount], left[amount], right[amount], current_node="AAA";
	int current = 0, steps = 0, index = 0;

	std::fstream file;
	file.open("AoC_D8.txt");
	getline(file, LR);
	getline(file, temp);
	for (int i = 0; i < amount; i++)
	{
		getline(file, temp);
		node[i] = temp.substr(0, 3);
		if (node[i] == "AAA")
			index = i;
		left[i] = temp.substr(7, 3);
		right[i] = temp.substr(12, 3);
	}
	file.close();

	while (current_node != "ZZZ")
	{
		if (LR[current] == 'R')
			current_node = right[index];
		else if (LR[current] == 'L')
			current_node = left[index];

		for (int i = 0; i < amount; i++) {
			if(node[i]==current_node) {
				index = i;
				break;
			}
		}
		current++;
		steps++;
		if (current >= LR.length())
			current = 0;
	}

	std::cout << steps;

	return 0;
}
