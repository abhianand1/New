#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Destination {
  char name[50];
  int cost;
  struct Destination *left;
  struct Destination *right;
};

struct Destination *createDestination(char *name, int cost) {
  struct Destination *destination = (struct Destination*)malloc(sizeof(struct Destination));
  strcpy(destination->name, name);
  destination->cost = cost;
  destination->left = NULL;
  destination->right = NULL;
  return destination;
}

struct Destination *insertDestination(struct Destination *root, char *name, int cost) {
  if (root == NULL) return createDestination(name, cost);
  if (cost <= root->cost)
    root->left = insertDestination(root->left, name, cost);
  else
    root->right = insertDestination(root->right, name, cost);
  return root;
}

void inOrderTraversal(struct Destination *root) {
  if (root == NULL) return;
  inOrderTraversal(root->left);
  printf("Destination: %s, Cost: %d\n", root->name, root->cost);
  inOrderTraversal(root->right);
}

int main() {
  struct Destination *root = NULL;
  char name[50];
  int budget, cost;

  printf("Enter your budget: ");
  scanf("%d", &budget);

  while (1) {
    printf("Enter destination name (or 'done' to exit): ");
    scanf("%s", name);
    if (strcmp(name, "done") == 0) break;
    printf("Enter the cost of the trip to %s: ", name);
    scanf("%d", &cost);
    if (cost <= budget) root = insertDestination(root, name, cost);
  }

  printf("\nDestinations within your budget:\n");
  inOrderTraversal(root);

  return 0;
}
