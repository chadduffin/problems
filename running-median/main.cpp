#include <queue>
#include <vector>
#include <iostream>

void runningMedian(const std::vector< int > &list);

int main(int argc, char **argv) {
  std::vector< int > list = {1, 3, 7, 10, 13, 18, 25};

  runningMedian(list);

  return 0;
}

void runningMedian(const std::vector< int > &list) {
  std::priority_queue< int, std::vector< int >, std::less< int > > largerNumbers;
  std::priority_queue< int, std::vector< int >, std::greater< int > > smallerNumbers;

  for (int value : list) {
    if ((largerNumbers.empty()) || (largerNumbers.top() > value)) {
      largerNumbers.push(value);
    } else {
      smallerNumbers.push(value);
    }

    if (smallerNumbers.size() > largerNumbers.size()+1) {
      largerNumbers.push(smallerNumbers.top());
      smallerNumbers.pop();
    } else if (largerNumbers.size() > smallerNumbers.size()+1) {
      smallerNumbers.push(largerNumbers.top());
      largerNumbers.pop();
    }

    if (smallerNumbers.size() == largerNumbers.size()) {
      std::cout << (smallerNumbers.top()+largerNumbers.top())/2.0 << std::endl;
    } else {
      if (smallerNumbers.size() > largerNumbers.size()) {
        std::cout << smallerNumbers.top() << std::endl;
      } else {
        std::cout << largerNumbers.top() << std::endl;
      }
    }
  }
}
