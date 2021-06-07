#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
void Print(Node* root){
    if(root==NULL){
        return ;
    }
    Print(root->left);
    cout<<root->data<<" ";
    Print(root->right);
}

Node* GetNewNode(int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
Node* Insert(Node* root, int data){
    if(root==NULL){
        root=GetNewNode(data);
        return root;
    }
    else if(data<=root->data)
        root->left=Insert(root->left,data);
    else
        root->right=Insert(root->right,data);
    return root;
}
bool Search(Node* root, int data){
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return Search(root->left,data);
    else  return Search(root->right,data);

}
int main()
{
    int num;
    Node* root=NULL;
    root=Insert(root,15);
    root=Insert(root,20);
    root=Insert(root,10);
    root=Insert(root,40);
    root=Insert(root,5);
    root=Insert(root,30);
    cout<<"The BST inorder traversal is:\n";
    Print(root);
    cout<<"\nEnter the number to be searched\n";
    cin>>num;
    if(Search(root,num)== true) cout<<"Found\n";
    else cout<<"Not found\n";
    return 0;
}
