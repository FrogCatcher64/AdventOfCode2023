#include <iostream>
#include <fstream>
#include <string>

#define size 20
void SavingData(std::string line, long long seeds[], long long data[])
{
	long long len=0, dstart=0, sstart=0, seed=0, distance=0;
	std::string temp;

	temp = line.substr(0, line.find(' '));
	dstart = stoll(temp);
	line.erase(0, line.find(' ')+1);
	temp = line.substr(0, line.find(' '));
	sstart = stoll(temp);
	line.erase(0, line.find(' ')+1);
	len = stoll(line);

	for (int i = 0; i < size; i++)
	{
		seed = seeds[i];
		if (seed >= sstart && seed<=sstart+len-1)
			data[i] = dstart + (seed-sstart);
	}
	for (int i = 0; i < size; i++) {
		if (data[i] == 0)
			data[i] = seeds[i];
	}
}

int main()
{
	std::fstream file;
	std::string trash, temp, map;
	file.open("AoC_D5.txt");
	long long seeds[size]{ 0 };
	long long soil[size]{ 0 }, fertilizer[size]{ 0 }, light[size]{ 0 }, water[size]{ 0 }, temperature[size]{ 0 }, humidity[size]{ 0 }, location[size]{ 0 };

	getline(file, trash, ':');
	getline(file, temp);
	temp.erase(0, 1);
	for (int i = 0; i < size-1; i++) { // pobranie nasion do tablicy seeds
		seeds[i] = stoll(temp.substr(0, temp.find(' ')));
		temp.erase(0, temp.find(' ') + 1);
	}
	seeds[size-1] = stoll(temp);
	getline(file, trash);

	while (!file.eof())
	{
		getline(file, map);
		if (map == "seed-to-soil map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp,seeds, soil);
			}
		}
		else if (map == "soil-to-fertilizer map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp, soil, fertilizer);
			}
		}
		else if (map == "fertilizer-to-water map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp, fertilizer, water);
			}
		}
		else if (map == "water-to-light map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp, water, light);
			}
		}
		else if (map == "light-to-temperature map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp, light, temperature);
			}
		}
		else if (map == "temperature-to-humidity map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp, temperature, humidity);
			}
		}
		else if (map == "humidity-to-location map:") {
			while (true) {
				getline(file, temp);
				if (!(isdigit(temp[0])))
					break;

				SavingData(temp, humidity, location);
			}
		}
	}
	long long min = location[0];
	for (int i = 0; i < size; i++)
	{
		if (location[i] < min)
			min = location[i];
	}
	std::cout << min;
	file.close();
	return 0;
}