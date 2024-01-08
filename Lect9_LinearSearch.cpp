#include<bits/stdc++.h>
using namespace std;


bool linearSearch(int arr[],int n,int ele){
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            return true;
        }
    }
    return false;
}

bool linearSearchFRecursive(int arr[],int index,int ele){
    //Base Case - 
    if(index<0){
        return false;
    }

    if(arr[index]==ele){
        return true;
    }

    //Recursive Case - 
    return linearSearchFRecursive(arr,index-1,ele);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ele;
    cout<<"Enter the elemnent - ";
    cin>>ele;

    // if(linearSearch(arr,n,ele)){
    //     cout<<"Element Found."<<endl;
    // }else{
    //     cout<<"Element Not Found."<<endl;
    // }

    if(linearSearchFRecursive(arr,n-1,ele)){
        cout<<"Element Found."<<endl;
    }else{
        cout<<"Element Not Found."<<endl;
    }
    return 0;
}