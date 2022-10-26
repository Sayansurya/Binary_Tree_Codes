#include <iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};


//Function to check whether a Binary Tree is BST or not.
    /*bool issublesser(Node *root, int value){
        if(root==NULL) return true;
        if(root->data<=value
           && issublesser(root->left,value)
           && issublesser(root->right,value))
           return true;
        else 
        return false;
    }
    bool issubgreater(Node *root, int value){
        if(root==NULL) return true;
        if(root->data>value
           && issubgreater(root->left,value)
           && issubgreater(root->right,value))
           return true;
        else 
        return false;
    }
    bool isBST(Node* root) 
    {
        // Your code here
        if(root==NULL){
            return true;
        }
        if(issublesser(root->left,root->data)
            && issubgreater(root->right,root->data)
            && isBST(root->left)
            && isBST(root->right))
        return true;
        else
        return false;
        
    }*/
    //BST should have distinct values
    bool isutil(Node *root, int minval, int maxval){
        if(root==NULL) return true;
        if(root->data>minval && root->data<maxval 
            && isutil(root->left, minval,root->data)
            && isutil(root->right,root->data,maxval))
        return true;
        else{
            return false;
        }
    }
    bool isBST(Node* root){
        int int_max=100000;
        int int_min=-100000;
        return isutil(root, int_min,int_max);
    }
    
};



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
    cout<<isBST(root);
    return 0;
}


// code by Sayan Surya Shaw
