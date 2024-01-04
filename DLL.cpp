#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed: " << value << endl;
    }
};

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
    curr->next->prev = temp;
    temp->prev = curr;
    curr->next = temp;
}
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next==NULL){
            tail = prev;
        }
        curr -> prev = NULL;
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

    insertAtHead(head, 13);
    print(head);
    insertAtHead(head, 18);
    print(head);
    insertAtTail(tail, 13);
    print(head);
    insertInMiddle(head, tail, 4, 245);
    print(head);

    deleteNode(4, head, tail);
    print(head);
}