#include<iostream>
using namespace std;
 
class Stack{
    // properties
      public:
        int *arr;
        int top;
        int size;


    // Behavior
    Stack(int size){
        this->size = size;
        arr = new int(size);
        top=-1;
    }
    void push(int element){
          if(size-top>1){
            top++;
            arr[top] = element;
          }
          else{
            cout<<"-::stack is full::-"<<endl;
          }
    }
    void pop(){
       if(top>=0){
        top--;

       }
       else{
        cout<<"-::stack is empty::-"<<endl;
       }
    }
    int peek(){
        if(top>=0){
        cout<<"Top of the stack is: "<<endl;
        return arr[top];
        }
        else{
        cout<<"Stack is empty::-"<<endl;
        return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack st(5);

    st.push(22);
    st.push(84);
    st.push(4);
    st.push(47);
    
    cout<<st.peek()<<endl;
    st.pop();
    
    cout<<"Pop called: "<<endl;
    cout<<st.peek()<<endl;
    cout<<"is stack empty?: "<<st.isEmpty()<<endl;


    return 0;
}