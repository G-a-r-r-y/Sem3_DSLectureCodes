// Process to Create a Single Threaded Binary Tree - 
// Step 1 - Make a simple binary tree but the structure of node will now also include bool rThread variable where - 
//          rThread = 1: Indicates a normal link to the child node
//          rThread = 0: Indicates a thread pointing to the in-order predecessor or in-order successor
// Note - While making the structure of the node class, set rThread=1 (default).

// Step 2 - Make a Threaded Function to convert the simple binary tree to a threaded binary tree - 
//          For this, first get a vector of node* type having the inorder of the tree and then just 
//          connect every node's rightChild link in this vector to its successor node if the current node's both children are NULL. 

#include<bits/stdc++.h>
using namespace std;

//Construction - 
class node{
    public:
    int data;
    node* left;
    node* right;
    bool rThread;
    node(int d){
        data=d;
        rThread=1;
    }
};

//For creating simple binary tree - 
node* createTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node* n=new node(d);
    n->left=createTree();
    n->right=createTree();
    return n;
}


//Converting it to a single threaded tree - 
void inOrderVectorMaking(node* root,vector<node*>&inOrderVector){
    if(root==NULL){
        return;
    }

    inOrderVectorMaking(root->left,inOrderVector);
    inOrderVector.push_back(root);
    inOrderVectorMaking(root->right,inOrderVector);
    return;
}

void singleThreadTree(vector<node*>&inOrderVector){
    for(int i=0;i<inOrderVector.size();i++){
        node* temp=inOrderVector[i];
        if(temp->left==NULL and temp->right==NULL and i!=inOrderVector.size()-1){ //Remember the conditions
            temp->right=inOrderVector[i+1];
            temp->rThread=0;
        }
    }
}


// --------------------------------------------------------------------------------------------------------------
//InOrder Traversal -

//Simple inOrder Output (without Threading) - 
void inOrderSimple(node* root){
    if(root==NULL){
        return;
    }

    inOrderSimple(root->left);
    cout<<root->data<<' ';
    inOrderSimple(root->right);
    return;
} 

// Single Threaded Inorder Traversal - 
// Algo - 
// Step 1 - Traverse to the leftMost node of the tree, set it as current node and print it's data. 
// Step 2 - Check its rThread - 
//          1. if rThread is connected to its simple right subTree(i.e rThread=1), set current node to the leftMost of its right subTree.
//          2. if rThread is connected to its Inorder successor(i.e rThread=0), just set current node to right child.
// Step 3 - Do the same procedure again and again till current node becomes NULL.

// Note - If the inOrder of both threaded and simple binary tree is same then single threading is done correctly.

// NO RECURSION IS INVOLVED!!!!!!!!!! 

node* leftMostNode(node* root){
    if(root==NULL){
        return root;
    }

    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

void inOrderThreaded(node* root){
    node* curr=leftMostNode(root);
    while(curr!=NULL){
        cout<<curr->data<<" ";
        if(curr->rThread==0){
            curr=curr->right;
        }else{
            curr=leftMostNode(curr->right);
        }
    }
}  

// -------------------------------------------------------------------------------------------------------------

int main(){
    // Input - 10 7 2 -1 -1 9 -1 -1 12 11 -1 -1 14 13 -1 -1 20 -1 -1 (PreOrder)
    // In Order - 2 7 9 10 11 12 13 14 20 

    node* root=createTree();
    cout<<"Simple InOrder - "<<endl;
    inOrderSimple(root);
    cout<<endl;

    
    //Threading - 
    vector<node*>inOrderVector;
    inOrderVectorMaking(root,inOrderVector);
    singleThreadTree(inOrderVector);

    //Checking if the Threaded tree is formed correctly or not using Threaded inorder Traversal - 
    cout<<"Threaded InOrder - "<<endl;
    inOrderThreaded(root);
    cout<<endl;
    return 0;
}