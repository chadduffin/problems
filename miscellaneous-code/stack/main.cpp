#include <iostream>

#include "stack.h"

int main(int argc, char **argv) {
  Stack< int > stack;

  for (int i = 0; i < 16; i++) {
    stack.Push(i);
  }

  for (int i = 0; i < 16; i++) {
    std::cout << stack.Pop() << std::endl;
  }

  return 0;
}

