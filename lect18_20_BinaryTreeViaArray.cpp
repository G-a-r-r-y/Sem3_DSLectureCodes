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

node* createTreeUsingArr(int index,int arr[],int sizeArr){
    //Base Case - 
    if(index>=sizeArr){
        return NULL;
    }

    //Recursive Case - 
    node* root=new node(arr[index]);
    root->left=createTreeUsingArr(2*(index)+1,arr,sizeArr);
    root->right=createTreeUsingArr(2*(index)+2,arr,sizeArr);
    return root;
    
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    node* root=createTreeUsingArr(0,arr,10);
    preOrder(root);
    return 0;
}