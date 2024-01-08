#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r){
    //Important conditions - 
    int pivot=arr[r];
    int i=l-1;

    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quick(int arr[],int l,int r){
    //Base Case - 
    if(l>=r){
        return;
    }

    //Recursive Case - 
    int p=partition(arr,l,r);
    quick(arr,l,p-1);
    quick(arr,p+1,r);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quick(arr,0,n-1);
    
    cout<<"After Quick Sort - "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}