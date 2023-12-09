#include <iostream>
#include <fstream>
#include <string>
#include <numeric> 

#define amount 798

unsigned long long NWW(unsigned long long a, unsigned long long b)
{
	unsigned long long mult = a * b, answer;
	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;

	answer = mult / a;
	return answer;
}

int main()
{
	std::string temp, LR, node[amount], left[amount], right[amount], current_node;
	int current = 0, steps = 0, index[6] = { 0 }, k = 0, indexs = 0;
	int step[6];
	unsigned long long answer = 1;

	std::fstream file;
	file.open("AoC_D8.txt");
	getline(file, LR);
	getline(file, temp);
	for (int i = 0; i < amount; i++)
	{
		getline(file, temp);
		node[i] = temp.substr(0, 3);
		if (node[i][2] == 'A')
		{
			index[k] = i;
			k++;
		}
		left[i] = temp.substr(7, 3);
		right[i] = temp.substr(12, 3);
	}
	file.close();
	
	for(int j=0; j<k; j++)
	{
		indexs = index[j];
		current = 0;
		current_node = node[index[j]];
		while (current_node[2] != 'Z')
		{
			if (LR[current] == 'R')
				current_node = right[indexs];
			else if (LR[current] == 'L')
				current_node = left[indexs];

			for (int i = 0; i < amount; i++) {
				if (node[i] == current_node) {
					indexs = i;
					break;
				}
			}
			current++;
			steps++;
			if (current >= LR.length())
				current = 0;
		}
		step[j] = steps;
		steps = 0;
	}

	answer = NWW(step[0], step[1]);
	for (int i = 2; i < k; i++) {
		answer = NWW(answer, step[i]);
	}
	std::cout << answer;
	return 0;
}
