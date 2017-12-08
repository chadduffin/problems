#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>

struct Node {
  int val;
  std::vector< Node* > children;
};

void traverseInOrder(Node *root);

int main(int argc, char **argv) {
  Node *root = new Node, *child;

  root->val = 0;

  //
  // this loop creates a basic n-ary tree
  //
  //                  0
  //                 /|\
  //                / | \
  //               1  2  3 
  //              /|\
  //             / | \
  //            4  5  6
  //

  for (int i = 1; i < 7; i++) {
    child = new Node;
    child->val = i;

    if (i < 4) {
      root->children.push_back(child);
    } else {
      root->children.at(0)->children.push_back(child);
    }
  }

  traverseInOrder(root);

  return 0;
}

void traverseInOrder(Node *root) {
  unsigned int previousStackSize = 1;
  std::stack< Node*, std::vector< Node* > > stack;
  std::vector< Node* >::reverse_iterator it;

  // add initial root to stack
  stack.push(root);

  while (!stack.empty()) {
    // if the node at the top of the stack has no children, or the previous stack
    // size is larger than our current size
    if ((stack.top()->children.empty()) || (stack.size() < previousStackSize)) {
      previousStackSize = stack.size();

      // output the value of the node at the top of the stack
      std::cout << stack.top()->val << std::endl;

      // remove the node
      stack.pop();
    } else {
      previousStackSize = stack.size();

      // save a way to reference the current top of the stack
      // this is important because we are going to push onto the stack
      std::vector< Node* > *currentTop = &(stack.top()->children);

      // iterate across the current top node's children in reverse
      // add them to the stack
      for (it = currentTop->rbegin(); it != currentTop->rend(); ++it) {
        stack.push(*it);
      }
    }
  }
}
