// Note - 
// An Interpolation Search is an improvement over Binary Search for scenarios where 
// the values in a sorted array are uniformly distributed.
// Binary Search goes to the middle element to check. 
// On the other hand, Interpolation Search may go to different locations according to the value of the key being searched.
// For example, if the value of the key is close to the last element, Interpolation Search is likely to start 
// search toward the end side.

// Important!!!
// Array must be Sorted!!!

//Formula - lo + ((hi - lo)/(arr[hi]-arr[lo]))*(ele-arr[lo])

#include<bits/stdc++.h>
using namespace std;


bool interPol(int arr[],int lo,int hi,int ele){
    
    if(lo<=hi and ele>=arr[lo] and ele<=arr[hi]){               //Important Condition to check.
        int pos=lo+((hi-lo)/(arr[hi]-arr[lo]))*(ele-arr[lo]);
        if(arr[pos]==ele){
            return true;
        }else if(arr[pos]<ele){
            return interPol(arr,pos+1,hi,ele);
        }else{
            return interPol(arr,lo,pos-1,ele);
        }
    }
    return false;
    
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ele;
    cout<<"Enter the element you wish to find - ";
    cin>>ele;
    if(interPol(arr,0,n-1,ele)){
        cout<<"Element Found."<<endl;
    }else{
        cout<<"Element Not Found."<<endl;
    }
    return 0;
}