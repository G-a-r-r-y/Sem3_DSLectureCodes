//Note - 
//Using this algorithm you can find out median as well as kth smallest element.

//Algorithm - 
// 1. Randomly pick pivot element from arr[] and the using the partition step from the quick sort algorithm 
//    arrange all the elements smaller than the pivot on its left and the elements greater than it on its right.
// 2. If after the previous step, the position of the chosen pivot is the middle of the array then it is 
//    the required median of the given array.
// 3. If the position is before the middle element then repeat the step for the subarray starting 
//    from previous starting index and the chosen pivot as the ending index.
// 4. If the position is after the middle element then repeat the step for the subarray starting 
//    from the chosen pivot and ending at the previous ending index.

// Note that in case of even number of elements, the middle two elements have to be found and their average will be the median of the array.
#include<bits/stdc++.h>
using namespace std;

int medianSearch(int arr[],int l,int r,int k){
    int j=0,m=0,n=0;
    int s1[30],s2[30],s3[30];
    
    int index=rand()%(r-l+1);

    for(int i=0;i<=r;i++){         //yeh 0 se hi start hoga!!
        if(arr[i]<arr[index]){
            s1[j]=arr[i];
            j++;
        }else if(arr[i]==arr[index]){
            s2[m]=arr[i];
            m++;
        }else{
            s3[n]=arr[i];
            n++;
        }
    }

    if(j>=k){
        return medianSearch(s1,0,j-1,k);  // 0 hi pass karenge naaki l and s1 pass hoga
    }else if((j+m)>=k){
        return arr[index];
    }else{
        return medianSearch(s3,0,n-1,k-(j+m)); // 0 hi pass karenge naaki l and s2 pass hoga
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int k;
    cout<<"Enter the value of 'k' - ";
    cin>>k;
    int element=medianSearch(arr,0,n-1,k);
    cout<<"Kth smallest element - "<<element;
    return 0;
}