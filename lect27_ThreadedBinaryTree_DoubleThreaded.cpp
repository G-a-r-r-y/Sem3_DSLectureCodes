// Process to Create a Double Threaded Binary Tree -
// Same Process as that of single threaded tree, just remember, here we have to write 2 functions - 
// 1. First to connect right threads 
// 2. Second to connect left threads
// And the structure of the node will now also contain a bool lThread variable with a default value of 1;

#include<bits/stdc++.h>
using namespace std;

//Construction - 
class node{
    public:
    int data;
    node* left;
    node* right;
    bool rThread;
    bool lThread;
    node(int d){
        data=d;
        rThread=1;
        lThread=1;
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


void inOrderVectorMaking(node* root,vector<node*>&inOrderVector){
    if(root==NULL){
        return;
    }

    inOrderVectorMaking(root->left,inOrderVector);
    inOrderVector.push_back(root);
    inOrderVectorMaking(root->right,inOrderVector);
    return;
}

// Function 1(For Right Threading) - 
void connectRightThreads(vector<node*>&inOrderVector){
    //Making 1st node's (i.e 2 in this case) lThread=0, inOrder printing mei kaam aata hai aage.
    node* firstNode=inOrderVector[0];
    firstNode->lThread=0;

    //Connecting rThreads - 
    for(int i=0;i<inOrderVector.size();i++){
        node* temp=inOrderVector[i];
        if(temp->right==NULL and temp->rThread==1 and i!=inOrderVector.size()-1){ //Remember the conditions
            temp->right=inOrderVector[i+1];
            temp->rThread=0;
        }
    }
}

// Function 2(For left Threading) -
// Note - Call this function only after reversing the vector in the main section.

void connectLeftThreads(vector<node*>&inOrderVector){
    //Making 1st node's (i.e 20 in this case, after reversing the vector) rThread=0, inOrder printing mei kaam aata hai aage.
    node* firstNode=inOrderVector[0];
    firstNode->rThread=0;

    //Connecting lThreads - 
    for(int i=0;i<inOrderVector.size();i++){
        node* temp=inOrderVector[i];
        // Note - Conditions mei mirror effect aaya hai
        if(temp->left==NULL and temp->lThread==1 and i!=inOrderVector.size()-1){ //Remember the conditions
            temp->left=inOrderVector[i+1];
            temp->lThread=0;
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

// Double Threading Inorder Traversal -
// Algo - 
// Step 1 - Find the left Most Node and set it as current node.
// Step 2 - Print current node's data and set current node to its inorder successor.
// Step 3 - Do step 2 till current node is not equal to root node.
// Step 4 - Print root node's data(right now, current node=root node)
// Step 5 - Call the whole function again if the current node is not threaded on the right side.

// Note - Base Condition -> Do this till we reach a node which is right Theaded but is pointing to a null value
//                          on its right side.

node* leftMostNode(node* curr){
    while(curr->lThread==1){
        curr=curr->left;
    }
    return curr;
}

node* inOrderSuccessor(node* curr){
    if(curr->rThread==0){
        return curr->right;
    }
    
    curr=curr->right;
    curr=leftMostNode(curr);
    return curr;
}

void inOrderTraversalTheaded(node* root){
    //Base Case - 
    if(root->rThread==0 and root->right==NULL){
        cout<<root->data;
        return;
    }

    //Recursive Case - 
    node* curr=leftMostNode(root);
    while(curr!=root){
        cout<<curr->data<<" ";
        curr=inOrderSuccessor(curr);
    }

    cout<<curr->data<<" "; 
    if(curr->rThread==1){
        inOrderTraversalTheaded(curr->right);
    }
}

// -----------------------------------------------------------------------------------------------------------------------
// Error Finding helping functions - 

void printVector(vector<node*>v){
    for(auto x:v){
        cout<<x->data<<" ";
    }
    cout<<endl;
}

// ----------------------------------------------------------------------------------------------------------------------
int main(){
    // Input - 10 7 2 -1 -1 9 -1 -1 12 11 -1 -1 14 13 -1 -1 20 -1 -1 (PreOrder)
    // In Order - 2 7 9 10 11 12 13 14 20  
    // Reverse In Order - 20 14 13 12 11 10 9 7 2

    node* root=createTree();
    cout<<"Simple InOrder - "<<endl;
    inOrderSimple(root);
    cout<<endl;

    
    //Threading - 
    vector<node*>inOrderVector;
    inOrderVectorMaking(root,inOrderVector);
    connectRightThreads(inOrderVector);
    //Reversing the vector here before preforming left threading.
    reverse(inOrderVector.begin(),inOrderVector.end());
    connectLeftThreads(inOrderVector);

    //Checking if the Threaded tree is formed correctly or not using Threaded inorder Traversal - 
    cout<<"Threaded Inorder - "<<endl;
    inOrderTraversalTheaded(root);
    cout<<endl;
    return 0;
}