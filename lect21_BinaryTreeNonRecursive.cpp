// Code nhi chal raha!!!!


#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node* left;
    node* right;
    node(char ch){
        data=ch;
        left=NULL;
        right=NULL;
    }
};

//Build Tree(PreIn) - 
node* preIn(char pre[],char in[],int s,int e){
    //Base Case - 
    if(s>e){
        return NULL;
    }

    //Recursive Case - 
    static int i=0;        // For starting index of PreOrder
    char data=pre[i];      // Assinging root node's data
    i++;

    //Finding left and right partition in inOrder for the current root node 
    int k;                    
    for(int l=s;l<=e;l++){
        if(data==in[l]){
            k=l;
            break;
        }
    }

    node* root=new node(data);
    root->left=preIn(pre,in,s,k-1); 
    root->right=preIn(pre,in,k+1,e);
    return root;
}

// NonRecursive Traversal, Uses Stack!!! - 
//1. Pre-Order(NLR)- 
//Method - a. Insert root into stack
//         b. Print root and delete it from stack
//         c. Insert root's right child into stack if it exists.
//         d. Insert root's left child into stack if it exists.
//         e. Do this till stack is not empty.
// Note- We are inserting root's right child first cause stack follows LIFO
void preOrder(node* root){
    stack<node*>s;
    if(root==NULL){
        return;
    }
    s.push(root);
    while(!s.empty()){
        node* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL){
            s.push(temp->right);
        }
        if(temp->left!=NULL){
            s.push(temp->left);
        }
    }
}


//2. In-Order(LNR) - 
//Method - a. Make an empty stack and temp=root;
//         b. Make a while loop with 2 conditions 
//         c. Make an another inside while loop to insert left children of temp 
//         d. Make temp = top of stack and pop it
//         e. Print temp's data and make temp=temp->rightChild

void inOrder(node* root){
    stack<node*>s;
    if(root==NULL){
        return;
    }
    node* temp=root;
    while(temp!=NULL || !s.empty()){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right; 
    }
}

//3. Post-Order using 2 stacks -
//Method - a. Make 2 empty stack s1,s2.
//         b. s2 will store the correct printing order with the help of s1.
//         c. insert root into s1
//         d. Make temp = top of s1 and pop it
//         e. insert temp into s2 (s2 mei insert bas yahi hoga)
//         f. if temp's left is not null, insert it into s1
//         g. if temp's right is not null, insert it into s1
//         h. After coming out of while loop, print s2.
// Note- In step f and g, we are checking root's left child first cause stack follows LIFO

void postOrder(node* root){
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        node* temp=s1.top();
        s1.pop();
        s2.push(temp);          // s2 mei push bas yaha ho raha hai
        if(temp->left!=NULL){
            s1.push(temp->left);
        }
        if(temp->right!=NULL){
            s1.push(temp->right);
        }
    }

    //Printing -
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    } 
} 

//4. Print Level Wise - 
void printLvlWise(node* root){
    queue<node*>q;
    q.push(NULL);   //This NULL is important!!
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){      //Important check condition
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){   //Check for null
                q.push(temp->left);
            }
            if(temp->right!=NULL){  //Check for null
                q.push(temp->right);
            }
        }
    }
}
int main(){
    char in[]={'g','d','h','b','e','i','a','f','j','c'};
    char pre[]={'a','b','d','g','h','e','i','c','f','j'};
    node* root=preIn(pre,in,0,9);

    cout<<"PreOrder - ";
    preOrder(root);
    cout<<endl;

    cout<<"InOrder - ";
    inOrder(root);
    cout<<endl;

    cout<<"PostOrder- ";
    postOrder(root);
    cout<<endl;

    cout<<"Level Wise - ";
    printLvlWise(root);
    return 0;
}