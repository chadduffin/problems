#include <stack>
#include <iostream>

void moveTower(int src, int dst, int tmp, int size, std::stack< int > *towers);

int main(int argc, char **argv) {
  std::stack< int > towers[3];

  towers[0].push(5);
  towers[0].push(4);
  towers[0].push(3);
  towers[0].push(2);
  towers[0].push(1);

  moveTower(0, 2, 1, 5, towers);

  while (!towers[2].empty()) {
    std::cout << towers[2].top() << " ";
    towers[2].pop();
  }

  std::cout << std::endl;

  return 0;
}

void moveTower(int src, int dst, int tmp, int size, std::stack< int > *towers) {
  if (size == 0) {
    return;
  }

  moveTower(src, tmp, dst, size-1, towers);

  towers[dst].push(towers[src].top());
  towers[src].pop();

  moveTower(tmp, dst, src, size-1, towers);
}

