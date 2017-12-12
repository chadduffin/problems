#include "animal.h"
#include "duck.h"

int main(int argc, char **argv) {
  Animal *generic = new Animal, *duck = new Duck;

  generic->Says();
  duck->Says();

  return 0;
}

