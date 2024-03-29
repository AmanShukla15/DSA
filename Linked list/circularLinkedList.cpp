#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory deallocated :: "<< value <<endl;
    }
};

void insertNode(Node* & tail, int element, int d){

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    // Non-empty list
    // assuming that the element is present in Linked list.
    else{

       Node* curr = tail;

       while(curr->data!=element){
        curr = curr->next;
       }
    // element found -> curr is representing element wala node
    Node* temp = new Node(d);
    temp -> next = curr -> next;
    curr -> next = temp;
    }
}

void print(Node* tail){
     Node* temp = tail;
     if(tail==NULL){
        cout<<"List is empty!"<<endl;
     }
     do{
     cout<<tail->data <<" ";
     tail = tail -> next;
     }while (tail != temp);
    
     cout<<endl;
}
void deleteNode(Node* &tail, int value){
       //empty list
       if(tail==NULL){
        cout<<"List is empty, please check again "<<endl;
        return;
       }    
       else{ 
        // Non-empty list  
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(curr==prev){
            tail = NULL;
        }
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
       }
}


int main(){
     Node* tail = NULL;
     
    //  empty list insertion
     insertNode(tail, 5, 3);
     print(tail);
     insertNode(tail, 3, 32);
    //  insertNode(tail, 32, 312);
    //  insertNode(tail, 312, 17);
    //  print(tail);
    // insertNode(tail, 32, 17);
    // print(tail);

    // deleteNode(tail, 312);
    // print (tail);
    deleteNode(tail, 3);
    print (tail);


    return 0;
}