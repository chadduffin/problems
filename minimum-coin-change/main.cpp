#include <vector>
#include <iostream>

void coinChangeMinimum(std::vector< int > &denominations, int total);

int main(int argc, char **argv) {
  std::vector< int > denominations = {1, 5, 6, 8};

  coinChangeMinimum(denominations, 11);

  return 0;
}

void coinChangeMinimum(std::vector< int > &denominations, int total) {
  std::vector< int > coinCount(total+1, INT_MAX),
                     backtracking(total+1, 0);

  // set the number of coins for change 0 to 0
  coinCount.at(0) = 0;

  // iterate through each denomination
  for (int value : denominations) {
    // begin at the first index this denomination fits
    for (unsigned int i = value; i < total+1; i++) {
      // check if using this coin will reduce our current coin count
      if ((i >= value) && (coinCount.at(i-value)+1 < coinCount.at(i))) {
        coinCount.at(i) = coinCount.at(i-value)+1;
        backtracking.at(i) = value;
      }
    }
  }

  std::cout << "The minimum number of coins needed to make change is "
            << coinCount.back() << ". These coins are: {";

  for (unsigned int i = total; i > 0;) {
    std::cout << backtracking.at(i);

    i -= backtracking.at(i);

    if (i == 0) {
      std::cout << "}\n";
    } else {
      std::cout << ", ";
    }
  }
}

