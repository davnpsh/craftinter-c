#include "challenges/01.h"

int main() {

  Node *ptr = generate_d_linked_list(4);

  traverse_d_linked_list(ptr);

  delete_node(ptr, 3);

  traverse_d_linked_list(ptr);

  return 0;
}