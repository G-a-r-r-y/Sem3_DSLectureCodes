#include<bits/stdc++.h>
using namespace std;

void count(int arr[],int n){
    //Finding Max Element - 
    int maxNum=arr[0];
    for(int i=0;i<n;i++){
        if(maxNum<arr[i]){
            maxNum=arr[i];
        }
    }

    //Making a new array - 
    int temp[maxNum]={0};           //Note - initialise by 0 karna zaruri hai!!

    //Inserting values in new array -  
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }

    //Commulative Sum - 
    for(int i=1;i<=maxNum;i++){    //Note - Yeh wala loop maxNum(including) tak chalega!!!
        temp[i]=temp[i]+temp[i-1];
    }

    //Making an output array - 
    int output[n];
    for(int i=n-1;i>=0;--i){
        int index=temp[arr[i]]-1;
        output[index]=arr[i];
        temp[arr[i]]--;
    }   

    //Copying output array into arr array - 
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    count(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}