#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

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
            next = NULL;
        }
        cout << "Memory freed: " << value << endl;
    }
};
void insertAtNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *newNode = new Node(d);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is Empty.." << endl;
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr -> data != value){
             prev = curr;
             curr = curr->next;
        }
        prev -> next = curr -> next;
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *tail)
{
    Node *curr = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != curr);
    cout << endl;
}
int main()
{

    Node *tail = NULL;
    insertAtNode(tail, 10, 13);
    print(tail);
    insertAtNode(tail, 13, 5);
    print(tail);
    insertAtNode(tail, 13, 10);
    print(tail);
    insertAtNode(tail, 13, 92);
    print(tail);
    insertAtNode(tail, 92, 15);
    print(tail);
    deleteNode(tail,13);
    print(tail);
    return 0;
}