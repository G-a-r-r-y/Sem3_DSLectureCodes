//Heaps implementation using vector  - 

#include<bits/stdc++.h>
using namespace std;

class minHeap{
    vector<int>v;
    public:
    minHeap(){
        v.push_back(-1);
    }


    // Insert - 
    void insert(int d){
        v.push_back(d);
        int child=v.size()-1;
        while(child!=1){
            int parent=child/2;
            if(v[parent]>v[child]){
                swap(v[parent],v[child]);
            }
            child=parent;   
        }
    }


    void heapify(int i){
        int minIndex=i;
        int leftChild=2*i;
        int rightChild=2*i+1;
        if(leftChild<v.size() and v[minIndex]>v[leftChild]){
            minIndex=leftChild;
        }
        if(rightChild<v.size() and v[minIndex]>v[rightChild]){
            minIndex=rightChild;
        }

        if(minIndex!=i){
            swap(v[minIndex],v[i]);
            heapify(minIndex);
        }
    }

    // Top - 
    int top(){
        return v[1];
    }

    // Pop - 
    void pop(){
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        if(v.size()==1){
            return true;
        }
        return false;
    }
};

int main(){
    minHeap h;
	h.insert(1);
	h.insert(2);
	h.insert(3);
	h.insert(17);
	h.insert(19);
	h.insert(36);
	h.insert(7);
	h.insert(25);
	h.insert(100);
	h.insert(0);

	while(!h.empty()){
		cout<<h.top()<<" ";
    	h.pop();
	}
    return 0;
}