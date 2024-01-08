//Note - 
// Find the minimum element in unsorted array and swap it with the element at beginning.
// Ulta of Bubble sort in a way just the process of doing is different.

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Selection Sort - 
    for(int i=0;i<n-1;i++){
        int smallestEleIndex=i;
        for(int j=i+1;j<n;j++){ 
            if(arr[j]<arr[smallestEleIndex]){
                smallestEleIndex=j;
            }
        }
        swap(arr[smallestEleIndex],arr[i]);
    }    

    //Printing array - 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}