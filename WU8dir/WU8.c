#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; // value of the node
    struct Node* next; // pointer to the next node
} Node;

typedef struct LinkedList{
  Node* head; // pointer to the first node in the list
} LinkedList;

Node* newNode(int newData);
LinkedList* newList();
void push(LinkedList* L,int newData);
void deleteNode(LinkedList* L,int key);
void printList(LinkedList* L);

int main(){
  // create new LinkedList (stored as a pointer)
  LinkedList* L=newList();
  // add nodes
  push(L,7);
  push(L,1);
  push(L,3);
  push(L,2);
  // print current list state
  printf("\nCreated Linked list is:\n");
  printList(L);
  // delete a node
  deleteNode(L,2);
  // print current list state
  printf("\nLinked List after Deletion of 1:\n");
  printList(L);
  return 0;
}
