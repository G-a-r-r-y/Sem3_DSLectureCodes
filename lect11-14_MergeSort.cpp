#include<bits/stdc++.h>
using namespace std;


// Is function mei mainly dhyaan do har variable kis value se initialise ho rha hai,
// hamesha 0 se nhi hota.
void merge2SortedArrays(int arr[],int s,int e){
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;

    int k=s;
    int temp[1000];
    
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
			temp[k]=arr[i];
			k++;
			i++;
		}
		else{
			temp[k]=arr[j];
			k++;
			j++;
		}
    }

    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }

    while(j<=e){
		temp[k]=arr[j];
		j++;
		k++;
	}

    for(int l=s;l<=e;l++){
        arr[l]=temp[l];
    }
    return;
}


void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }

    int mid=(s+e)/2;
    mergeSort(arr,s,mid);   //Note - mid tak chalega including mid
    mergeSort(arr,mid+1,e);
    merge2SortedArrays(arr,s,e);
    return;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    cout<<"After Merge Sort - "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}