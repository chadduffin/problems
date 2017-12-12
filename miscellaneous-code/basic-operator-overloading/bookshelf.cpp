#include "bookshelf.h"

Bookshelf::Bookshelf(int count) : bookCount(count) {
  // default constructor
}

Bookshelf::~Bookshelf(void) {
  // default destructor
}

int Bookshelf::BookCount(void) {
  return bookCount; 
}

void Bookshelf::operator+(Bookshelf &other) {
  bookCount += other.bookCount;
}

