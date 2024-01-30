/*
I used the following two sources for help no this:
https://www.geeksforgeeks.org/typedef-in-c/
  helped me understand typedef and typedef struct
ChatGPT
  helped me come up with the double pointer idea and how to use malloc()
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; // value of the node
    struct Node* next; // pointer to the next node
} Node;

// creates a new node with value newData
Node* newNode(int newData){
  Node* newNode=(Node*)malloc(sizeof(Node)); // create a new empty node
  newNode->data=newData; // set the data field
  newNode->next=NULL; // no following node by default
  return newNode; // outputs a pointer to where the new node is stored in memory
}

typedef struct LinkedList{
  Node* head; // pointer to the first node in the list
} LinkedList;


// adds a new node with value newData at the head of the list (pointing to the previous head)
void push(LinkedList* L,int newData){
    Node* newHead=newNode(newData); // create a new node with a value of newData
    newHead->next=L->head; // set the new node to point to the memory address of the current head of L
    L->head=newHead; // update the head of L to be the new node
    //return newNode; // return the newly created node
}

void deleteNode(LinkedList* L,int key){ // we need a pointer to the head pointer incase head is the node we need to delete
  Node* temp=L->head;
  Node* prev=NULL; // variables to store the current node

  // if the head node is the node we need to delete
  if(temp!=NULL && temp->data==key){
    L->head=temp->next; // make the pointer to head point to the next node
    free(temp); // clear the memory slot that stored the old head
    return; // end the function
  }

  // Search for the key to be deleted
  while(temp!=NULL && temp->data!=key){
    prev=temp;
    temp=temp->next;
  }

  // If the key was not present in the linked list
  if(temp->next==NULL){
    return; // end the function
  }

  prev->next=temp->next; // Unlink the node from the linked list (overwrite the pointer to the node we are deleting)
  free(temp); // Free the memory of the node to be deleted
}

void printList(LinkedList* L) {
  Node* temp=L->head; // stores the current element
  // prints each successive element to the list
  while (temp!=NULL){
    printf("%d ", temp->data); //print
    temp = temp->next; // next node
  }
  printf("\n");
}

int main(){
    LinkedList* L=(LinkedList*)malloc(sizeof(LinkedList));

    push(L,7);
    push(L,1);
    push(L,3);
    push(L,2);

    printf("\nCreated Linked list is:\n");
    printList(L);

    deleteNode(L,2);

    printf("\nLinked List after Deletion of 1:\n");
    printList(L);

    return 0;
}
