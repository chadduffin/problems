#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>

std::vector< int >* countOccurences(const std::vector< int > &list, int n);

int main(int argc, char **argv) {
  std::vector< int > list = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4}, *occurences;

  std::random_shuffle(list.begin(), list.end());

  occurences = countOccurences(list, 2);

  for (int value : *occurences) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;
}

std::vector< int >* countOccurences(const std::vector< int > &list, int n) {
  auto lambda = [](const std::pair< int, int > &left, const std::pair< int, int > &right) -> bool { return left.second > right.second; };

  std::vector< int > *result = new std::vector< int >;
  std::unordered_map< int, int > occurences;
  std::priority_queue< std::pair< int, int >, std::vector< std::pair< int, int > >, decltype(lambda) > mostOccurences(lambda);

  // for every value in the list
  for (int value : list) {
    if (occurences.count(value)) {
      // increment occurence if it is in list already
      occurences[value] = occurences[value]+1;
    } else {
      // otherwise, add to list
      occurences[value] = 1;
    }
  }

  for (auto it = occurences.begin(); it != occurences.end(); it++) {
    mostOccurences.push(*it);

    if (mostOccurences.size() > n) {
      mostOccurences.pop();
    }
  }

  while (!mostOccurences.empty()) {
    result->push_back((mostOccurences.top()).first);
    mostOccurences.pop();
  }

  return result;
}
