#ifndef __ANIMAL__
#define __ANIMAL__

#include <iostream>

class Animal {
  public:
    Animal(void);
    virtual ~Animal(void);

    virtual void Says(void);
};

#endif /* ANIMAL */
