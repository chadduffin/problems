#include <iostream>

#include "bookshelf.h"

int main(int argc, char **argv) {
  Bookshelf small(5), large(20);

  small+large;

  std::cout << small.BookCount() << std::endl;

  return 0;
}

