#ifndef __DUCK__
#define __DUCK__

#include "animal.h"

class Duck : public Animal {
  public:
    Duck(void);
    ~Duck(void);

    void Says(void);
};

#endif /* DUCK */

