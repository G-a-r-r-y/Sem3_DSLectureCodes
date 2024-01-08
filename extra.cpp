// Dijkstra's algorithm is an algorithm for finding
// the shortest paths between nodes in a weighted graph, 

#include<bits/stdc++.h>
using namespace std;
template<typename U>

class graph{
    unordered_map<U,list<pair<U,int>>> h; //Remember Syntax for making a pair inside a list.
    //here list will store the destinatino value + weight of that link
    public:
    void addEdge(U x,U y,int weight,bool isBidirectional=true){
        h[x].push_back(make_pair(y,weight));
        if(isBidirectional==true){
            h[y].push_back(make_pair(x,weight));
        }
    }
    void printGraph(){
        for(auto x:h){
            cout<<x.first<<" --> ";
            for(auto z:x.second){
                cout<<'('<<z.first<<','<<z.second<<')'<<" ";
            }
            cout<<endl;
        }
    }

    void dijkstrasAlgo(U src, U dest, int noOfnodes){
        //A set is a data structure that stores unique elements of the same type in a sorted order.
        set<pair<int,U>>s;

        //Distance array is storing distance of each key from the source
        int distance[noOfnodes]; //Note - noOfnodes+1
        for(int i=0;i<noOfnodes;i++){
            distance[i]=INT_MAX;
        }

        distance[src]=0;
        s.insert({0,src});
        while(!s.empty()){
            auto it=*(s.begin());  
            int tempDistance=it.first;
            U tempKey=it.second;
            s.erase(it);

            for(auto x:h[tempKey]){
                U tempKey2=x.first;
                int edgeWeight=x.second;
                if(tempDistance+edgeWeight<distance[tempKey2]){ // relaxation Process
                    // erase if it existed, mtlb koi already uss node pe pahuch chuka hai
                    // and uska key,value pair bhi stored hai in the set, so delete that now 
                    // cause of ab kisi kaam ka nahi raha
                    if(distance[tempKey2]!=INT_MAX){    
                        s.erase({distance[tempKey2],tempKey2});
                    }
                    distance[tempKey2]=tempDistance+edgeWeight;
                    s.insert({distance[tempKey2],tempKey2});
                }
            }
        }
        
        for(auto x: distance){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<"Minimum distance between "<<src<<" and "<<dest<<" is "<<distance[dest]<<endl;
    }
};

int main(){

    //Given Graph(Striver wala) - 
//     0           3
//     | \       /   \
//     |  \4   3/     \2
//     |   \   /       \
//     |    \ /    6    \
//    4|     2  -------  5
//     |    / \         /
//     |   /   \       /
//     |  /2   1\     /3
//     | /       \   /
//     1           4

    graph<int>g;
    g.addEdge(0,1,4);
    g.addEdge(0,2,4);
    g.addEdge(2,3,3);
    g.addEdge(2,4,1);
    g.addEdge(2,5,6);
    g.addEdge(2,1,2);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);
    g.printGraph();
    //g.dijkstrasAlgo(0,1,6);
    g.dijkstrasAlgo(0,5,6);
    return 0;
}