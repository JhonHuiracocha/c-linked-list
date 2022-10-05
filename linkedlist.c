#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node * next;
};

void menu();
bool isEmpty(struct Node * head);
bool includes(struct Node * head, int data);
struct Node * createNode(int data);
struct Node * add(struct Node * head, int data);
struct Node * find(struct Node * head, int data);
struct Node * delete(struct Node * head, int data);
struct Node * sort(struct Node * head);
void swap(struct Node * a, struct Node * b);
void printList(struct Node * head);

int main() {

  menu();

  return 0;
}

void menu() {
  int option = 0, data = 0;
  struct Node * head = NULL;

  do {

    printf("\n\t\t>>> LINKEDLIST <<<\n\n");
    printf("\t\t1. Add\n");
    printf("\t\t2. Print list\n");
    printf("\t\t3. Find\n");
    printf("\t\t4. Delete\n");
    printf("\t\t5. Sort\n");
    printf("\t\t6. Exit\n\n");
    printf("\t\tEnter a option: ");
    scanf("%i", & option);

    switch (option) {
    case 1:

      printf("\n\t\t*** Add ***\n\n");
      printf("\t\tEnter a number: ");
      scanf("%i", & data);

      head = add(head, data);

      break;

    case 2:

      if (isEmpty(head)) {
        printf("\n\t\tThe list is empty\n\n");
        break;
      }

      printf("\n\t\t*** Print List ***\n\n");
      printList(head);

      break;

    case 3:

      if (isEmpty(head)) {
        printf("\n\t\tThe list is empty\n\n");
        break;
      }

      printf("\n\t\t*** Find ***\n\n");
      printf("\t\tEnter the number to search: ");
      scanf("%i", & data);

      struct Node * found = find(head, data);

      if (!found) {
        printf("\n\t\tThe number has not been found\n\n");
        break;
      }

      printf("\n\t\tNumber: %i\n\n", found -> data);

      break;

    case 4:

      if (isEmpty(head)) {
        printf("\n\t\tThe list is empty\n\n");
        break;
      }

      printf("\n\t\t*** Delete ***\n\n");
      printf("\t\tEnter the number to delete: ");
      scanf("%i", & data);

      bool exists = includes(head, data);

      if (!exists) {
        printf("\n\t\tThe number has not been found\n\n");
        break;
      }

      head = delete(head, data);

      printf("\n\t\tThe number has been deleted successfully\n\n");

      break;

    case 5:

      head = sort(head);
      
      printf("\n\t\tThe linked list has been sorted\n\n");

      break;
    }

  } while (option != 6);
}

bool isEmpty(struct Node * head) {
  return head == NULL;
}

bool includes(struct Node * head, int data) {
  struct Node * aux = head;

  if (head == NULL)
    return false;

  while (aux != NULL) {
    if (aux -> data == data)
      return true;

    aux = aux -> next;
  }

  return false;
}

struct Node * createNode(int data) {
  struct Node * temp = malloc(sizeof(struct Node));
  temp -> data = data;
  temp -> next = NULL;
  return temp;
}

struct Node * add(struct Node * head, int data) {
  struct Node * aux = NULL;
  struct Node * temp = createNode(data);

  if (head == NULL) {
    head = temp;
    return head;
  }

  aux = head;

  while (aux -> next != NULL)
    aux = aux -> next;

  aux -> next = temp;

  return head;
}

struct Node * find(struct Node * head, int data) {
  struct Node * aux = head;
  struct Node * current = NULL;

  if (head == NULL)
    return NULL;

  while (aux != NULL) {
    if (aux -> data == data)
      current = aux;

    aux = aux -> next;
  }

  return current;
}

struct Node * delete(struct Node * head, int data) {
  struct Node * aux = head;
  struct Node * temp = NULL;

  if (head == NULL)
    return NULL;

  if (head -> data == data) {
    temp = head;
    head = head -> next;

    free(temp);

    return head;
  }

  while (aux -> next != NULL && (aux -> next) -> data != data)
    aux = aux -> next;

  temp = aux -> next;
  aux -> next = (aux -> next) -> next;

  free(temp);

  return head;
}

struct Node * sort(struct Node * head) {
  struct Node * aux = head;
  struct Node * temp = NULL;

  if (head == NULL)
    return head;

  while (aux != NULL) {
    temp = aux -> next;

    while (temp != NULL) {
      if (aux -> data > temp -> data)
        swap(aux, temp);

      temp = temp -> next;
    }

    aux = aux -> next;
  }

  return head;
}

void swap(struct Node * a, struct Node * b) {
  int temp = a -> data;
  a -> data = b -> data;
  b -> data = temp;
}

void printList(struct Node * head) {
  struct Node * aux = head;

  while (aux != NULL) {
    printf("\t\tNumber: %i\n", aux -> data);
    aux = aux -> next;
  }
}
