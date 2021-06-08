#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
int Min(Node *root){
    if(root==NULL){
        cout<<"Tree is empty\n";
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    else{
        return Min(root->left);
    }

}
int Max(Node *root){
    if(root==NULL){
        cout<<"Tree is empty\n";
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    else{
        return Max(root->right);
    }

}

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
    root=Insert(root,76);
    cout<<"The BST inorder traversal is:\n";
    Print(root);
    cout<<"\nThe minimum element of the BST is:  ";
    int x=Min(root);
    cout<<x;
    cout<<"\nThe maximum element of the BST is:  ";
    int y=Max(root);
    cout<<y;
    return 0;
}
