#include<bits/stdc++.h>
using namespace std;

//Note - Taking k=4
class node{
    public:
    int data;
    vector<node*>v;
    node(int d){
        data=d;
    }
};

void buildKTree(node* root){
    
    //Base Case - 
    if(root==NULL){
        return;
    }

    //Recursive Case - 
    //Taking Data - 
    int d;
    cout<<"Enter data for "<<root->data<<" - ";
    for(int i=0;i<4;i++){
        cin>>d;
        if(d==-1){
            root->v.push_back(NULL);
        
        }else{
            node* temp=new node(d);
            root->v.push_back(temp);
        }
    }
    
    //Recursive Calling - 
    for(auto x:root->v){
        buildKTree(x);
    }
}

// -------------------------------------------
// Traversal - 
// Note - In k-ary tree, there is no inOrder Traversal cause ismei midNode lena
//        possible nhi hai(slide mei k=3 diya hai toh woh bas uss case ke liye chalega)

void preOrder(node* root){
    
    //Base Case - 
    if(root==NULL){
        return;
    }

    //Recursive Case -  
    cout<<root->data<<" ";    
    //Recursive Calling - (Going left -> right)
    for(auto x:root->v){
        preOrder(x);
    }
    return;
}


void postOrder(node* root){
    //Base Case - 
    if(root==NULL){
        return;
    }

    //Recursive Case -      
    //Recursive Calling - (Going left -> right)
    for(auto x:root->v){
        postOrder(x);
    }
    cout<<root->data<<" ";
    return;
}

int main(){
    node* root=new node(1);
    buildKTree(root);
    cout<<"Pre-Order - "<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"Post-Order - "<<endl;
    postOrder(root);
    return 0;
}