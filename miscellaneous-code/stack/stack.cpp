template <typename T>
Stack<T>::Stack(void) {
  top = nullptr;
  size = 0;
}

template <typename T>
Stack<T>::~Stack(void) {
  Node *tmp;

  while ((tmp = top)) {
    top = top->next;

    delete tmp;
  }
}

template <typename T>
T Stack<T>::Pop(void) {
  T to_return = -1;
  Node *tmp;

  if ((tmp = top)) {
    to_return = top->data;
    top = top->next;
    size--;

    delete tmp;
  }

  return to_return;
}

template <typename T>
T Stack<T>::Peek(void) {
  T to_return = -1;

  if (top) {
    to_return = top->data;
  }

  return to_return; 
}

template <typename T>
void Stack<T>::Push(T value) {
  Node *to_add = new Node;

  to_add->data = value;
  to_add->next = top;
  top = to_add;
  size++;
}

