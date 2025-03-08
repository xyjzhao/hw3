#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // base case
  if (head== nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  // else, disconnect current node
  Node* current = head;
  head = head->next;
  current->next = nullptr;

  if (current->val <= pivot){
    smaller = current;

    Node* theNext = nullptr;
    llpivot(head, theNext, larger, pivot);
    smaller->next = theNext;
  }
  else {
    larger = current;

    Node* theNext = nullptr;
    llpivot(head, smaller, theNext, pivot);
    larger->next = theNext;
  }
}