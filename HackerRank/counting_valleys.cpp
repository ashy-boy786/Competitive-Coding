/*
	counting_valleys.cpp
*/

#include <iostream>
#include <vector>

using step_t = std::vector<char>;

step_t getSteps()
{
	int n {};
	std::cin >> n;

	step_t steps(n);

	for (auto& s : steps)
		std::cin >> s; 

	return steps;
}

int stepVal(char step)
{
	if (step == 'U')
		return 1;
	return -1;
}

int numValleys(step_t steps)
{
	int altitude {0};
	int num {0};

	for (const auto& s : steps)
	{
		if (altitude == 0 && stepVal(s) == -1)
			num++;
		altitude += stepVal(s);
	}
	return num;
}

int main()
{
	step_t steps { getSteps() };
	std::cout << numValleys(steps);
}