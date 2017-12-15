#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

std::vector< std::string >* findAllPermutations(const std::string &input);
void recursePermutations(const std::string &input, std::vector< std::string > *permutations, unsigned int index);

int main(int argc, char **argv) {
  std::string input = "abc";
  std::vector< std::string > *permutations = findAllPermutations(input);

  std::sort(permutations->begin(), permutations->end());

  for (std::string value : *permutations) {
    std::cout << value << std::endl;
  }

  return 0;
}

std::vector< std::string >* findAllPermutations(const std::string &input) {
  std::vector< std::string > *permutations = new std::vector< std::string >;

  recursePermutations(input, permutations, input.size()-1);

  return permutations;
}

void recursePermutations(const std::string &input, std::vector< std::string > *permutations, unsigned int index) {
  if (index == 0) {
    // default case
    permutations->push_back(input.substr(0, 1));
    return;
  } else {
    // down the rabbit hole!
    recursePermutations(input, permutations, index-1);

    int subsetCount = permutations->size();

    // for each permutation from the recursive call
    for (; subsetCount > 0; subsetCount--) {
      // save and remove the first permutation from the previous
      // recursive call
      std::string permutation = permutations->front();
      permutations->erase(permutations->begin());

      // add the character at index into each spot of the current permutation,
      // then add each of these new permutations to our list
      for (unsigned int j = 0; j < permutation.size(); j++) {
        permutations->push_back(permutation.substr(0, j)+
                                input.at(index)+
                                permutation.substr(j, permutation.size()-j));
      }

      // add the final permutation with the character at the end
      permutations->push_back(permutation+input.at(index));
    }
  }
}

