#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data: "<<value<<endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    // new node created
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    // new node created
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;

    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    // creating a  node for d
    Node *nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        // deleting first or start node
        head = head->next;
        // memory free from start node
        temp -> next=NULL; 
        delete temp;
    }
    else
    {
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr -> next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    // created a new node
    Node *node1 = new Node(10);

    // cout<<node1 -> data<<endl;
    // cout<<node1 -> next<<endl;

    // head pointed to node1;
    Node *head = node1;
    Node *tail = node1;
    print(head);

    InsertAtTail(tail, 14);
    InsertAtTail(tail, 15);
    print(head);
    InsertAtPosition(tail, head, 4, 12);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(3, head);
    print (head);

    return 0;
}