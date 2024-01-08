#include <bits/stdc++.h>
using namespace std;
template<typename U>

class graph{
    unordered_map<U,list<U>>h;
    public:
    
    void addEdge(U x,U y,bool isBidirectional=true){
        h[x].push_back(y);
        if(isBidirectional=true){
            h[y].push_back(x);
        }
    }

    void printGraph(){
        for(auto x:h){
            cout<<x.first<<"----->";
            for(auto z:x.second){
                cout<<z<<" "; 
            }
            cout<<endl;
        }
    }

    void dfs(U src,unordered_map<U,bool>&visited){
        cout<<src<<" ";
        visited[src]=true;
        for(auto x:h[src]){
            if(visited[x]==false){
                dfs(x,visited);
            }
        }
    }

};


int main(){
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
    cout<<"DFS - "<<endl;
    //Call karte waqt U ki jagah int, string, etc likhna hota hai.
    unordered_map<int,bool>visited;
    g.dfs(0,visited);
    return 0;
}