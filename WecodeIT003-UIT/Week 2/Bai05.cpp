#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;
        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};

void insert_node(SinglyLinkedList *p, int x){
  SinglyLinkedListNode* node = new SinglyLinkedListNode(x);
  if (p->head == nullptr) { 
      p->head = node;
      p->tail = node;
  } 
  else {
      p->tail->next = node;
      p->tail = node;
  }
}

void reverseLinkedList(SinglyLinkedList *p){
  SinglyLinkedListNode *next = nullptr;
  SinglyLinkedListNode *tmp = nullptr;
  SinglyLinkedListNode *Newnode = p->head;
  p->tail = p->head;
  while (Newnode != nullptr){
    next = Newnode->next;
    Newnode->next = tmp;
    tmp = Newnode;
    Newnode = next;
  }
  p->head = tmp; 
}

void printLinkedList(SinglyLinkedList *p){
  SinglyLinkedListNode *tmp = p->head;
  while (tmp != nullptr){
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
