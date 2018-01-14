#include <vector>
#include <iostream>

void countWaysToMakeChange(const std::vector< int > &coins, int amount);

int main(int argc, char **argv) {
	std::vector< int > coins;

	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(3);

	countWaysToMakeChange(coins, 4);

	return 0;
}
void countWaysToMakeChange(const std::vector< int > &coins, int amount) {
	std::vector< int > amounts(amount+1, 0);

	amounts.at(0) = 1;

	for (int value : coins) {
		for (unsigned int i = 0; i < amounts.size(); i++) {
			if (i >= value) {
				amounts.at(i) += amounts.at(i-value);
			}
		}
	}

	std::cout << amounts.back() << std::endl;
}
