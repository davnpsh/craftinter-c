#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

typedef struct {
  long data;
  int *prev;
  int *next;
} Node;

Node *create_node(long data) {
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

// concatenates 2 given nodes
void insert_node(Node *node, Node *node2) {
  node->next = (int *)node2;
  node2->prev = (int *)node;
}

Node *generate_d_linked_list(int n) {
  if (n < 1) {
    exit(1);
  }

  Node *ptr = create_node(0);

  Node *prev = ptr;

  for (int i = 1; i <= n; i++) {
    Node *next = create_node(i);

    insert_node(prev, next);

    prev = next;
  }

  return ptr;
}

// print all dll payload
void traverse_d_linked_list(Node *ptr) {
  Node *current = ptr;

  do {
    printf("%ld\n", current->data);
    current = (Node *)current->next;
  } while (current != NULL);
}

// find a node and return it according to its data
Node *find_node(Node *ptr, long data) {
  Node *current = ptr;
  while (current != NULL) {
    if (current->data == data) {
      return current;
    }
    current = (Node *)current->next;
  }

  return NULL;
}

// delete a node that contains certain data
void delete_node(Node *ptr, long data) {
  Node *found = find_node(ptr, data);

  if (found != NULL) {
    Node *prev = (Node *)found->prev;
    Node *next = (Node *)found->next;

    prev->next = (int *)next;
    next->prev = (int *)prev;

    free(found);

    printf("node deleted: %ld\n", data);
  } else {
    printf("nothing found :C\n");
  }
}

int main() {

  Node *ptr = generate_d_linked_list(4);

  traverse_d_linked_list(ptr);

  delete_node(ptr, 3);

  traverse_d_linked_list(ptr);

  return 0;
}