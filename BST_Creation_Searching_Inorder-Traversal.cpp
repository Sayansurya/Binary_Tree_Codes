#include <iostream>
#include<queue>
using namespace std;
//comment
struct Node{
    int data;
    Node* left;
    Node* right;
};
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+ 1;
}
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

void level_order(Node *root){
    if(root ==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
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
    root=Insert(root,76);
    cout<<"The BST inorder traversal is:\n";
    Print(root);
    cout<<"\nThe BST level order traversal is:\n";
    level_order(root);
    cout<<"\nThe minimum element of the BST is:  ";
    int x=Min(root);
    cout<<x;
    cout<<"\nThe maximum element of the BST is:  ";
    int y=Max(root);
    cout<<y;
    cout<<"\nThe height of BST: "<<height(root)<<"\n";
    cout<<"\nEnter the number to be searched\n";
    cin>>num;
    if(Search(root,num)== true) cout<<"Found\n";
    else cout<<"Not found\n";
    return 0;
}
