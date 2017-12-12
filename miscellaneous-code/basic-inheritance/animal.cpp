#include "animal.h"

Animal::Animal(void) {
  // default constructor
}

Animal::~Animal(void) {
  // virtual destructor
}

void Animal::Says(void) {
  std::cout << "<generic animal noise>\n";
}
