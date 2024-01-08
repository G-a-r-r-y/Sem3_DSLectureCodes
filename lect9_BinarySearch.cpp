//Note - 
//Binary search can be implemented only on a sorted list of items!!!!!!!!!!!

#include<bits/stdc++.h>
using namespace std;


bool binarySearch(int arr[],int n,int ele){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(e+s)/2;
        if(arr[mid]==ele){
            return true;
        }else if(arr[mid]<ele){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return false;
}


bool binarySearchRecursive(int arr[],int s,int e,int ele){
    int mid=(s+e)/2;

    //Base Case -
    if(s>e){
        return false;
    } 
    if(arr[mid]==ele){
        return true;
    }

    //Recursive Case - 
    if(arr[mid]<ele){
        return binarySearchRecursive(arr,mid+1,e,ele);
    }
    return binarySearchRecursive(arr,s,mid-1,ele);
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

    // if(binarySearch(arr,n,ele)){
    //     cout<<"Element Found."<<endl;
    // }else{
    //     cout<<"Element Not Found."<<endl;
    // }

    if(binarySearchRecursive(arr,0,n-1,ele)){
        cout<<"Element Found."<<endl;
    }else{
        cout<<"Element Not Found."<<endl;
    }

    return 0;
}