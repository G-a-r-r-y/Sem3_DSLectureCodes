#include<bits/stdc++.h>
using namespace std;


bool puttingAQueenPossible(int** matrix,int row,int col,int n){
    //row check
    for(int i=col;i>=0;i--){
        if(matrix[row][i]==1){
            return false;
        }
    }

    //Checking for diagonals - 
    //For upper diagonal - 
    int x=row;
    int y=col;
    while(x>=0 and y>=0){
        if(matrix[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    //For lower diagonal - 
    x=row;
    y=col;
    while(x<n and y>=0){
        if(matrix[x][y]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void solve(int** matrix,int col,int n){
    //Base Case - 
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }


    //Recursive Case - 
    for(int row=0;row<n;row++){
        if(puttingAQueenPossible(matrix,row,col,n)){
            matrix[row][col]=1;
            solve(matrix,col+1,n);

            //BackTracking - 
            matrix[row][col]=0;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;

    //Making a matrix - 
    int** matrix=new int*[n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[n];
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
        }
    }

    solve(matrix,0,n);
    return 0;
}