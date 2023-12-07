#include <iostream>
#include <string>

#define size 4
int main()
{
	int time[size]={60, 80, 86, 76}, distance[size]={601, 1163, 1559, 1300}, answer=1, ways = 0;
	long long TrueTime = 60808676, TrueDistance = 601116315591300;

	//Part 1 
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < time[i]; j++) {
			if ((time[i] - j) * j > distance[i])
				ways++;
		}
		answer *= ways;
		ways = 0;
	}
	std::cout << answer << " ";

	//Part2
	for (int j = 1; j < TrueTime; j++) {
		if ((TrueTime - j) * j > TrueDistance)
			ways++;
	}
	std::cout << ways;
	return 0;
}