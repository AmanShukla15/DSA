#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
       this->data = d;
       this->next = NULL;
    }
    ~Node(){
        int val = this -> data;
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"deleted memory is: "<<val<<endl;
    }
};
void insertNode(Node* &tail,int element, int d){
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
    
    
}
void deleteNode(Node* &tail, int value){
    if(tail==NULL){
        cout<<"List is empty:..... "<<endl;
        return;
    }
    else{
// List is not empty....
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data!=value){
        prev = curr;
        curr = curr->next;
    } 
    prev->next=curr->next; 
    if(curr == prev){
        tail = NULL;
    }
    else if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    }

}
void print(Node* &tail){
    Node* temp = tail;
    if(tail==NULL){
        cout<<"List is Empty...."<<endl;
    }
    do{
      cout<<tail->data<<" ";
      tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
int main(){
    Node* tail = NULL;
    insertNode(tail, 5,10);
    insertNode(tail, 10,20);
    insertNode(tail, 20,30);
    insertNode(tail, 20,40);
    print(tail);
    deleteNode(tail, 40);
    print(tail);
    return 0;
}