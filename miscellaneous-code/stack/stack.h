#ifndef __STACK__
#define __STACK__

#include <cstddef>

template <typename T = int>
class Stack {
  public:
    Stack(void);
    ~Stack(void);
    T Pop(void);
    T Peek(void);
    void Push(T value);

  private:
    class Node {
      public:
        T data;
        Node *next;
    };

    Node *top;
    size_t size;
};

#include "stack.cpp"

#endif /* STACK */

