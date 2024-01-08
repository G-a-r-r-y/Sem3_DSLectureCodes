//Direct/Separate Hashing - (Array + linked list)

#include<iostream>
using namespace std;

class node{
    public:
    string key;
    int value;
    node* next;
    node(string a,int b){
        key=a;
        value=b;
        next=NULL;
    }
};

class hashmap{
    node** arr;        // ** cause this pointer will point to the first index of the 
                       // array containing the first indices of different linked lists as its elements.
    int cs;            // Current Size
    int ts;            // Total Size 
    
    public:

    hashmap(int size=7){
        arr=new node*[size]; //dynamically making an array
        ts=size;
        cs=0;
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }
    }

    //HashFunction -
    //To convert the given string key to some integer value
    //Revisit why humne itni baar %ts kiya hai
    int hashFuntion(string s){
        int ans=0;
        int multi=1;
        for(int i=0;i<s.length();i++){
            ans=(ans%ts+((s[i]%ts*multi%ts)%ts))%ts; // ans=ans+s[i]*multi
            multi=(multi*29)%ts;
        }
        return ans%ts;
    }

    //Rehashing - 
    void rehashing(){
        node** oldArr=arr;
        int oldts=ts;

        //Making a new empty arr of double the initial size
        arr=new node*[ts*2];
        ts=2*ts;
        cs=0;
        for(int i=0;i<ts;i++){   //Hamesha pehle NULL values se initiate karo
            arr[i]=NULL;
        }

        //Copy
        for(int i=0;i<oldts;i++){
            node* head=oldArr[i];
            while(head!=NULL){
                insert(head->key,head->value);
                head=head->next;
            }
        }
    }

    void insert(string str,int value){
        int index=hashFuntion(str);
        node* n=new node(str,value);
        n->next=arr[index];
        arr[index]=n;
        cs++;
        if(cs/(ts*1.0)>0.5){
            rehashing();
        }
    }

    void print(){
        for(int i=0;i<ts;i++){
            cout<<i<<':';
            node* head=arr[i];
            while(head!=NULL){
                cout<<'('<<head->key<<','<<head->value<<')'<<" ";
                head=head->next;
            }
            cout<<endl;
        }
    }

    bool search(string key){
        int index=hashFuntion(key);   //Note - For the same key, index obtained will be always same.
        node* head=arr[index];
        while(head!=NULL){
            if(head->key==key){
                    return true;
                }
                head=head->next;
            }
        return false;
    }

};

int main(){
    hashmap h;
    h.insert("Garvit",23);
    h.insert("Gas",24);
    h.insert("rahut",26);
    h.insert("ttkeit",3);
    h.insert("manvit",222);
    h.insert("garit",444);
    h.insert("sadt",3);
    h.print();
    if(h.search("garisdft")==true){
        cout<<"Key present";
    }else{
        cout<<"Key not present";
    }
    return 0;
}