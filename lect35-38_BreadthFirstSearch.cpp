#include<bits/stdc++.h>
using namespace std;
template<typename U>

class graph{
    unordered_map<U,list<U>>h;
    public:
        void addEdge(U x,U y, bool isBidirectional=true){
            h[x].push_back(y);
            if(isBidirectional==true){
                h[y].push_back(x);
            }
        }

        void printGraph(){
            for(auto x:h){
                cout<<x.first<<"------------>";
                for(auto z:x.second){
                    cout<<z<<" ";
                }
                cout<<endl;
            }
        }

    //Breadth First Search(bfs) - 
    //The Breadth First Search (BFS) algorithm is used to search a graph data structure for a node that meets a set of criteria. 
    //It starts at the root of the graph and visits all nodes at the current depth level before 
    //moving on to the nodes at the next depth level.
    //Note - 1. In this we use a queue and an unordered map.
    //          Queue stores keys and unordered map stores whether the key is already visited or not.
    //       2. Remember to traverse adjacent nodes of the source and follow that trend.


    void bfs(U src){
        queue<U>q;
        unordered_map<U,bool>visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            U tempKey=q.front();
            q.pop();
            cout<<tempKey<<" ";
            for(auto x:h[tempKey]){
                if(visited[x]==false){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
    }
};

int main(){
    //Given Graph - 
    // 0 -- 1
    // |   /| \
    // |  / |  2    
    // | /  | /
    // 4 -- 3

    //Call karte waqt U define karna hota hai.
    graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,4);
	g.addEdge(1,3);
	g.addEdge(4,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
    cout<<"Printing Graph - "<<endl;
    g.printGraph();
    cout<<endl;
    cout<<"BFS - "<<endl;
    g.bfs(0);
    return 0;
}