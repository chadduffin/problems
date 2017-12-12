#include <stack>
#include <vector>
#include <iostream>

void stackSort(std::stack< int > &numberStack);

int main(int argc, char **argv) {
  std::stack< int > numberStack;
  std::vector< int > numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::random_shuffle(numbers.begin(), numbers.end());

  for (int value : numbers) {
    numberStack.push(value);
  }

  stackSort(numberStack);

  while (!numberStack.empty()) {
    std::cout << numberStack.top() << std::endl;
    numberStack.pop();
  }

  return 0;
}

void stackSort(std::stack< int > &numberStack) {
  int i, tmp;
  std::stack< int > tmpStack;

  while (!numberStack.empty()) {
    i = 0;
    tmp = numberStack.top();
    numberStack.pop();

    while ((!tmpStack.empty()) && (tmpStack.top() > tmp)) {
      numberStack.push(tmpStack.top());
      tmpStack.pop();
      i++;
    }

    tmpStack.push(tmp);
  
    while (i > 0) {
      tmpStack.push(numberStack.top());
      numberStack.pop();
      i--;
    }
  }

  while (!tmpStack.empty()) {
    numberStack.push(tmpStack.top());
    tmpStack.pop();
  }
}

