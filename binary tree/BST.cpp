#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d){
        this->data = d;
        this->left=NULL;
        this->right=NULL;

    }
};



Node* insertInToBST(Node* &root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(root->data<data){
        root->right = insertInToBST(root->right,data);
    }
    else{
        root->left = insertInToBST(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertInToBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //sperater
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){  //level is completly traversed
          cout<<endl;
          if(!q.empty()){ //queue still has some child nodes
            q.push(NULL);
          }
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);

        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}
void inorder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    // cout<<root->data<<" ";
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left !=NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    // base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        // 0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child
            // left child only
            if(root->left != NULL && root->right==NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // right child only
            if(root->left == NULL && root->right!=NULL){
                Node* temp = root->right;  
                delete root;
                return temp;
            }
        // 2 child
        if(root->left!=NULL&&root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }

    }
    else if(root->data >val){
        // left part mai jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        // right part mai jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    //deletion
    cout<<"Befor: level Order Traversal"<<endl;
   levelOrderTraversal(root);
    root = deleteFromBST(root, 50);
    cout<<"After: level Order Traversal"<<endl;
   levelOrderTraversal(root);

//    cout<<"inorder"<<endl;
//    inorder(root);
//    cout<<endl;
//    cout<<"preorder"<<endl;
//    preorder(root);
//    cout<<endl;
//    cout<<"postorder"<<endl;
//    postorder(root);
// 50 20 70 10 30 90 110 -1
    return 0;
}