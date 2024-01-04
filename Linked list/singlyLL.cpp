#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }


};

void insertAtHead(Node* &head, int d){
    //  New node create

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;   
}
void insertAtPosition(Node* &Tail,Node* &head, int position, int d){
    //  insert at start
    if(position==1){
        insertAtHead(head, d);
        return;
    }
    
     Node* temp = head;
     int cnt = 1;
     while(cnt<position-1){
        temp = temp->next;
        cnt++;
     }
    //  Inserting at last position
     if(temp->next==NULL){
         insertAtTail(Tail,d);
         return;
     }

    //  creating new node for d
     Node* nodeToInsert = new Node(d);
     nodeToInsert->next = temp->next;
     temp->next=nodeToInsert;
}
void deleteNode(int position, Node* &head,Node* &tail){
    //deleting at first position
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp->next = NULL;
        delete temp;
    }
    // deleting any middle and last node
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        
        prev->next = curr->next;
        if(position==4){
        tail = prev;

        }
        curr->next = NULL;

        delete curr;

    }
}  

void traversingLinkedList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    // created a new node
    Node* node1=new Node(10);
    
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1; 
    Node* position = node1;
    insertAtTail(tail, 12);
    traversingLinkedList (head);
    insertAtTail(tail, 15);
    traversingLinkedList (head);

    insertAtPosition(tail, head, 4, 22);
    traversingLinkedList(head);
    
    deleteNode(2, head,tail);
    traversingLinkedList(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
  
    return 0;
}