#ifndef __BOOKSHELF__
#define __BOOKSHELF__

class Bookshelf {
  public:
    Bookshelf(int count = 0);
    ~Bookshelf(void);
    int BookCount(void);
    void operator+(Bookshelf &other);
  
  private:
    int bookCount;
};

#endif /* BOOKSHELF */

