#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

// Insertion in BST - 
//Note - data rules ke according ki add karna padega like pehle root phir uske left and right and so on.
node* insertIntoBst(node* root,int d){                  
    if(root==NULL){      //For when the tree is empty
        root=new node(d);
    }else if(d<root->data){ //For left Subtree of bst
        root->left=insertIntoBst(root->left,d);
    }else{
        root->right=insertIntoBst(root->right,d);
    }
    return root;
}

node* buildBst(){
    node* root=NULL;
    int d;
    cin>>d;
    while(d!=-1){
        root=insertIntoBst(root,d);
        cin>>d;
    }
    return root;
}


// -----------------------------------------------------------------

void printLvlWise(node* root){
    queue<node*>q;
    q.push(NULL);   //This NULL is important!!
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

// ------------------------------------------------------------------------------
// Searching in BST -

//Note - Use BST property
// Approach: Just traverse the node from root to left recursively until left is NULL. 
// The node whose left is NULL is the node with the minimum value.
int smallestNode(node* root){  
    //Base Case - 
    if(root->left==NULL){
        return root->data;
    }

    //Recursive Case - 
    return smallestNode(root->left);
}

//Note - Use BST property
// Approach: Just traverse the node from root to right recursively until right is NULL. 
// The node whose right is NULL is the node with the maximum value.
int largestNode(node* root){ 
    //Base Case - 
    if(root->right==NULL){
        return root->data;
    }

    //Recursive Case - 
    return largestNode(root->right);
}


//Note - Use BST property
// Return type is node*
node* searchNode(node* root,int num){
    //Base Case - 
    if(root==NULL){
        return NULL;
    }
    if(root->data==num){
        return root;
    }

    //Recursive Case - 
    if(root->data>num){
        return searchNode(root->left,num);
    }
    return searchNode(root->right,num);
}


// ---------------------------------------------------------------------
//Deletion in BST (Iska bas algorithm dhung se dekho)- 
//Possible Cases - 
//1. Nodes does not exist
//2. Leaf Node
//3. Node with 1 child
//4. Node with 2 children

node* helpTraverse(node* root,node* currNode){         //This function helps in finding the parent element
    //Base - 
    if(root->left==currNode || root->right==currNode){
        return root;
    }
    
    //Recursive -
    if(currNode->data<root->data){
        return helpTraverse(root->left,currNode); 
    } 
    return helpTraverse(root->right,currNode);
}

node* smallestNodeOnRight(node* n,node* &ans){
    if(n->data<ans->data){
        ans=n;
    }else{
        smallestNodeOnRight(n->left,ans);
    }
    return ans;
}

void deleteNode(node* root,node* currNode){
    //Case 2 - 
    if(currNode->left==NULL and currNode->right==NULL){
        node* temp=helpTraverse(root,currNode);
        if(temp->left==currNode){
            temp->left=NULL;
        }else{
            temp->right=NULL;
        }
        delete currNode;
        return;
    }

    //Case 3 - 
    if(currNode->left==NULL and currNode->right!=NULL){
        node* temp=helpTraverse(root,currNode);
        temp->right=currNode->right;
        delete currNode;
    }else if(currNode->left!=NULL and currNode->right==NULL){
        node* temp=helpTraverse(root,currNode);
        temp->left=currNode->left;
        delete currNode;
    }   

    // Yeh Case Nahi chal raha !
    //Case 4 - 
    if(currNode->left!=NULL and currNode->right!=NULL){
        node* temp2=smallestNodeOnRight(currNode->right,currNode->right);
        currNode->data=temp2->data;
        
        node* temp=helpTraverse(root,temp2);
        if(temp->left==temp2){
            temp->left=NULL;
        }else{
            temp->right=NULL;
        }
        delete temp2;
        return;
    }
}


void deletionInBst(node* root,node* currNode,int num){
    //Base Case - 
    if(currNode==NULL){
        return ;
    }

    //Recursive Case - 
    if(currNode->data==num){
        deleteNode(root,currNode);
    }else if(currNode->data<num){
        deletionInBst(root,currNode->right,num);
    }else{
        deletionInBst(root,currNode->left,num);
    }
    return;
}

int main(){
    // Sample Input(From slide) - 
    // 43 10 79 90 12 54 11 9 50 -1
    node* root=buildBst();
    
    cout<<"Level Wise  - "<<endl;
    printLvlWise(root);
    cout<<endl;

    //Search Smallest Node - 
    int num1=smallestNode(root);
    cout<<"Smallest Node - "<<num1<<endl;

    //Search Largest Node - 
    int num2=largestNode(root);
    cout<<"Largest Node - "<<num2<<endl;

    //Search a speciifc Node - 
    // int num3;
    // cout<<"Enter the number you wish to search - ";
    // cin>>num3;
    // node* target=searchNode(root,num3);
    // if(target==NULL){
    //     cout<<"Node does not exist."<<endl;
    // }else{
    //     cout<<"Node exists"<<endl;
    // }

    //Deletion - 
    //deletionInBst(root,root,50);//LeafNode
    //deletionInBst(root,root,54); //One child
    deletionInBst(root,root,79);//two children
    cout<<"After Deletion"<<endl;
    printLvlWise(root);
    return 0;
}