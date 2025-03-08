#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct OddFilter {
    bool operator()(int val) { return val % 2 == 1; }
};

struct EvenFilter {
    bool operator()(int val) { return val % 2 == 0; }
};

struct GreaterThanFilter {
    int threshold;
    GreaterThanFilter(int thresh) : threshold(thresh) {}
    bool operator()(int val) { return val > threshold; }
};


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    
    Node* smaller = nullptr;
    Node* larger = nullptr;
    int pivot = 5;
    
    Node* headCopy = nullptr;
    Node* current = head;
    Node* tail = nullptr;
    
    while (current != nullptr) {
        if (headCopy == nullptr) {
            headCopy = new Node(current->val, nullptr);
            tail = headCopy;
        } else {
            tail->next = new Node(current->val, nullptr);
            tail = tail->next;
        }
        current = current->next;
    }
    
    cout << "Pivoting around " << pivot << endl;
    llpivot(headCopy, smaller, larger, pivot);
    
    cout << "Smaller list: ";
    print(smaller);
    cout << "Larger list: ";
    print(larger);
    cout << "Original list should be empty: ";
    print(headCopy);
    
    dealloc(smaller);
    dealloc(larger);
    
    Node* headCopy2 = nullptr;
    current = head;
    tail = nullptr;
    
    while (current != nullptr) {
        if (headCopy2 == nullptr) {
            headCopy2 = new Node(current->val, nullptr);
            tail = headCopy2;
        } else {
            tail->next = new Node(current->val, nullptr);
            tail = tail->next;
        }
        current = current->next;
    }
    
    OddFilter oddFilter;
    cout << "Filtering out odd numbers" << endl;
    Node* filteredList = llfilter(headCopy2, oddFilter);
    cout << "Filtered list (evens only): ";
    print(filteredList);
    
    dealloc(filteredList);
    
    Node* headCopy3 = nullptr;
    current = head;
    tail = nullptr;
    
    while (current != nullptr) {
        if (headCopy3 == nullptr) {
            headCopy3 = new Node(current->val, nullptr);
            tail = headCopy3;
        } else {
            tail->next = new Node(current->val, nullptr);
            tail = tail->next;
        }
        current = current->next;
    }
    
    EvenFilter evenFilter;
    cout << "Filtering out even numbers" << endl;
    filteredList = llfilter(headCopy3, evenFilter);
    cout << "Filtered list (odds only): ";
    print(filteredList);
    
    dealloc(filteredList);
    
    Node* headCopy4 = nullptr;
    current = head;
    tail = nullptr;
    
    while (current != nullptr) {
        if (headCopy4 == nullptr) {
            headCopy4 = new Node(current->val, nullptr);
            tail = headCopy4;
        } else {
            tail->next = new Node(current->val, nullptr);
            tail = tail->next;
        }
        current = current->next;
    }
    
    int threshold = 5;
    GreaterThanFilter gtFilter(threshold);
    cout << "Filtering out numbers > " << threshold << endl;
    filteredList = llfilter(headCopy4, gtFilter);
    cout << "Filtered list (numbers <= " << threshold << "): ";
    print(filteredList);
    
    dealloc(filteredList);
    dealloc(head);
    
    return 0;
}