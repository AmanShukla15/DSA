#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
       int val = this->data;
       if(next != NULL){
          delete next;
          next = NULL;
       }
       cout<<"Deleted data is : "<<val<<endl;
    }
};
// doubly linked list insertion
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(int position, Node *&head, Node *&tail, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    if (position == 4)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next = NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
// doubly linked list deletion
void deleteNode(int position, Node* &head, Node* &tail){
    
    if(position==1){
      Node* temp = head;
      temp->next->prev=NULL;
      head = temp->next;
      temp->next=NULL;
      delete temp;
    }
    else{

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while(cnt<position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    tail = prev;
    delete curr;
    }
}
// traversing a link list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 16);
    insertAtTail(tail, 15);
    print(head); 
    cout << "Length is: " << getLength(head) << endl;

    insertAtPosition(4, head, tail, 34);
    print(head);

    deleteNode(5,head,tail);
    print(head);
    cout << "Length is: " << getLength(head) << endl;
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    return 0;
}