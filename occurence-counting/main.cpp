#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>

class CompareDist {
  public:
    bool operator() (std::pair< int, int > n1, std::pair< int, int > n2) {
      return n1.second > n2.second;
    }
};

std::vector< int >* countOccurences(const std::vector< int > &list, int n);

int main(int argc, char **argv) {
  std::vector< int > list, *occurences;

  list.push_back(1);
  list.push_back(5);
  list.push_back(3);
  list.push_back(8);
  list.push_back(5);
  list.push_back(8);
  list.push_back(5);
  list.push_back(1);
  list.push_back(1);
  list.push_back(1);

  occurences = countOccurences(list, 2);

  for (int value : *occurences) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;
}

std::vector< int >* countOccurences(const std::vector< int > &list, int n) {
  std::vector< int > *result = new std::vector< int >;
  std::unordered_map< int, int > occurences;
  std::priority_queue< std::pair< int, int >, std::vector< std::pair< int, int > >, CompareDist > mostOccurences;

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
