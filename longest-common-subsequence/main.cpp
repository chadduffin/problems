#include <vector>
#include <string>
#include <iostream>

void longestCommonSubsequence(const std::string &first, const std::string &second);

int main(int argc, char **argv) {
  std::string first("abcdefg"),
              second("aqbwerctyd");

  longestCommonSubsequence(first, second);

  return 0;
}

void longestCommonSubsequence(const std::string &first, const std::string &second) {
  std::vector< std::vector< int > > subsequences(first.size(), std::vector< int >(second.size(), 0));

  for (auto it_first = first.begin(); it_first != first.end(); it_first++) {
    for (auto it_second = second.begin(); it_second != second.end(); it_second++) {
      int it_first_offset = it_first-first.begin(),
          it_second_offset = it_second-second.begin();

      if ((*it_first) == (*it_second)) {
        if ((it_first_offset > 0) && (it_second_offset > 0)) {
          subsequences.at(it_first_offset).at(it_second_offset) = subsequences.at(it_first_offset-1).at(it_second_offset-1)+1;
        } else {
          subsequences.at(it_first_offset).at(it_second_offset) = 1;
        }
      } else {
        int left = (it_first_offset > 0) ? (subsequences.at(it_first_offset-1).at(it_second_offset)) : 0,
            above = (it_second_offset > 0) ? (subsequences.at(it_first_offset).at(it_second_offset-1)) : 0;

        subsequences.at(it_first_offset).at(it_second_offset) = (left < above) ? above : left;
      }
    }
  }

  {
    int row = second.size()-1,
        col = first.size()-1,
        len = subsequences.back().back();
    std::string subsequence(len, ' ');

    while (len) {
      if ((col > 0) && (subsequences.at(col).at(row) == subsequences.at(col-1).at(row))) {
        col--;
      } else if ((row > 0) && (subsequences.at(col).at(row) == subsequences.at(col).at(row-1))) {
        row--;
      } else {
        subsequence.at(len-1) = first.at(col);

        col--;
        row--;
        len--;
      }
    }

    std::cout << subsequence << std::endl;
  }
}

