// Prim's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph.

// Notes for self!
// -> Required data structures
//     1. Min heap
//     2. Visited array
//     3. Mst list that will store all the edges that are a part of MST

// -> Datatypes of our data structures
//     Visited array => int
//     Mst list =>  (weight , node name , node parent)

// -> Steps
//     1. Mark the visited array as 0 for all the nodes
    
//     2. Start with 0th node and push
//        (0,0,-1)
//        explanation:  -1 means 0 is the genesis node
//        Mark 0 as visited

//     3. Push all the neighbours of 0 in pq Do not mark them visited  (footnote 1)
//        Since its a min heap the edge with minimum weight will be at the top

//     4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked 
//        node into pq

//     5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends


// -> Footnote:
//     1. why to not mark it visited?
//        in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up 
//        later for sure (algorithm ends only when the queue is empty )but in msts case even if we push the edge into pq, 
//        there is no surety that the edge will be picked up . when prims algo ends there are still a few non accepted 
//        edges present in the pq hence we only mark it visited once its picked up from pq.

//     2. A priority queue is a type of queue that arranges elements based on their priority values. 
//        Elements with higher priority values are typically retrieved before elements with lower priority values.



#include<bits/stdc++.h>
using namespace std;
template<typename U>

class graph{
    unordered_map<U,list<pair<U,int>>>h;
    public:
    
    void addEdge(U x,U y,int wt,bool isBidirectional=true ){
        h[x].push_back(make_pair(y,wt));
        if(isBidirectional==true){
            h[y].push_back(make_pair(x,wt));
        }
    }

    void printGraph(){
        for(auto x:h){
            cout<<x.first<<"------->";
            for(auto z:x.second){
                cout<<'('<<z.first<<','<<z.second<<"), ";
            }
            cout<<endl;
        }
    }

    int primsAlgo(U x,int noOfNodes){
        int visited[noOfNodes]={0};
        priority_queue<pair<int,pair<int,U>>,vector<pair<int,pair<int,U>>>,greater<pair<int,pair<int,U>>>>q;
        vector<pair<U,U>>MST;
        int sum=0;

        q.push({0,{0,-1}});
        visited[0]=1;

        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int weight=it.first;
            int node=it.second.first;
            int parent=it.second.second;

            if(visited[node]==0){
               MST.push_back({node,parent}); 
               visited[node]=1;
               sum+=weight;
            }

            for(auto x:h[node]){
                if(visited[x.first]!=1){
                    q.push({x.second,{x.first,node}});
                }
            }
        }
        return sum;
    }
};


int main(){
//        2
//     0------1     4
//     |     /    /    \
//    1|   1/   2/      \
//     |   /    /        \ 1
//     |  /    /          \ 
//     | /    /    2       \
//       2 ---------------- 3

    graph<int>g;
    g.addEdge(0,1,2);
    g.addEdge(0,2,1);
    g.addEdge(2,1,1);
    g.addEdge(2,4,2);
    g.addEdge(2,3,2);
    g.addEdge(4,3,1);
    g.printGraph();
    int primSum=g.primsAlgo(0,6);
    cout<<primSum<<endl;
    return 0;
}


