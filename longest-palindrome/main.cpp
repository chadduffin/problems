#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

void longestPalindromicSubsequence(std::string input);

int main(int argc, char **argv) {
  std::string input = "agbdba";

  longestPalindromicSubsequence(input);

  return 0;
}

void longestPalindromicSubsequence(std::string input) {
  std::vector< std::vector< int > > palindromeData(input.size(), std::vector< int >(input.size(), 0));

  // initialize the matrix diagonal with value 1
  for (auto it = palindromeData.begin(); it != palindromeData.end(); it++) {
    it->at(it-palindromeData.begin()) = 1.0;
  }

  for (int width = 1; width < input.size(); width++) {
    for (int row = 0, col = width; col < input.size(); row++, col++) {
      if (input.at(row) == input.at(col)) {
        if (width == 1) {
          palindromeData.at(col).at(row) = 2;
        } else {
          palindromeData.at(col).at(row) = palindromeData.at(col-1).at(row+1)+2;
        }
      } else {
        palindromeData.at(col).at(row) = std::max(palindromeData.at(col-1).at(row),
                                                  palindromeData.at(col).at(row+1));
      }
    }
  }

  std::cout << palindromeData.back().front();
}

