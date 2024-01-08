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

//Building a Binary Tree - 
node* buildBT(){
    //Base Case - 
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    //Recursive Case - 
    node* root=new node(d);
    root->left=buildBT();
    root->right=buildBT();
    return root;
}


//Printing Techniques (All Recursive Methods)- 
// Note - Pre, In and Post -> Depth first search techniques.
//        Level Wise -> Breadth first search technique.

//1. Pre-Order (NLR)
void preOrder(node* root){
    //Base Case - 
    if(root==NULL){
        return;
    }

    //Recursive Case - 
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

//2. In-Order (LNR)
void inOrder(node* root){
    //Base Case - 
    if(root==NULL){
        return;
    }

    //Recursive Case - 
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

//3. Post-Order (LRN)
void postOrder(node* root){
    //Base Case - 
    if(root==NULL){
        return;
    }

    //Recursive Case - 
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}


//4. Level Wise - 
void printLvlWise(queue<node*>&q){
    if(q.empty()){
         return;
    }

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
    printLvlWise(q);
    return;
}


//Applications - 

//1.height of tree -
// Note - end mei -1 bhi karna final answer mei se   
int height(node* root){
    //Base Case - 
    if(root==NULL){
        return 0;
    }

    //Recursive Case - 
    return 1+max(height(root->left),height(root->right));
}


//2.number of Nodes -
int numOfNodes(node* root){
    //Base Case - 
    if(root==NULL){
        return 0;
    }

    //Recursive Case - 
    return 1+numOfNodes(root->left)+numOfNodes(root->right);
} 


// Sample Case - 
// Input - 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// Note - input preOrder ke format mei hi hoga with -1 for leaf nodes.

// Output - 
// Pre-Order - 1 2 4 5 3 6 7 
// In-Order - 4 2 5 1 6 3 7 
// Post-Order - 4 5 2 6 7 3 1 
int main(){
    node* root=NULL;
    root=buildBT();

    cout<<endl<<"Printing Techniques - "<<endl;
    cout<<"Pre-Order - ";
    preOrder(root);
    cout<<endl;

    cout<<"In-Order - ";
    inOrder(root);
    cout<<endl;

    cout<<"Post-Order - ";
    postOrder(root);
    cout<<endl;

    cout<<"Level Wise - ";
    queue<node*>q;
    q.push(NULL);
    q.push(root);
    printLvlWise(q);

    cout<<endl;
    cout<<"Applications - "<<endl;
    cout<<"Height - "<<height(root)-1<<endl;
    cout<<"Number Of Nodes - "<<numOfNodes(root)<<endl;
    return 0;
}