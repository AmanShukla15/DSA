#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout<<"Enter the data for left side of: "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right side of: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); //sperater
    while(!q.empty()){
        node* temp = q.front();
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
/*
:: Traversal techniques ::
(L-left, N-node, R-right);
1. inorder(LNR);
2. preorder(NLR);
3. postorder(LRN);
*/
void inorder(node* root){
    // base case
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    // cout<<root->data<<" ";
}
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter data for root: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    /*
    // this part is to check traversal technique
    // creating tree
    root = buildTree(root);

    // level order 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"printing the level of binary tree"<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder traversal:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal:"<<endl;
    postorder(root);
    */

    return 0;
}
