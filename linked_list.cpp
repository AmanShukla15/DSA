#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free from node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);

    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}
void insertInMiddle(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *curr = head;
    Node *temp = new Node(d);

    int cnt = 1;
    while (cnt < position - 1)
    {
        curr = curr->next;
        cnt++;
    }
    if (curr->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(int position, Node *&head, Node* &tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next == NULL){
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
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
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    insertAtHead(head, 21);
    print(head);
    insertAtHead(head, 24);
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtTail(tail, 43);
    print(head);
    insertAtTail(tail, 32);
    print(head);

    cout << "Insertion at middle" << endl;
    insertInMiddle(head, tail, 7, 99);
    print(head);

    deleteNode(1, head, tail);
    print(head);

    return 0;
}