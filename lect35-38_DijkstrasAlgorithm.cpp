// Note - ismei hashmap mei U + pair save hoga!!.
// Dijkstra's algorithm is an algorithm for finding
// the shortest paths between nodes in a weighted graph.

// NOTE - CODE MEI KAHI DIKKAT AA RHI HAI!!!

#include<bits/stdc++.h>
using namespace std;
template<typename U>

class graph{
    unordered_map<U,list<pair<U,int>>> h; //Remember Syntax for making a pair inside a list.
                                          //here list will store the destinatino value + weight of that link
    public:
    void addEdge(U x,U y,int weight,bool isBidirectional=true){
        h[x].push_back(make_pair(y,weight)); //Remember make_pair()
        if(isBidirectional==true){
            h[y].push_back(make_pair(x,weight));
        }
    }
    void printGraph(){
        for(auto x:h){
            cout<<x.first<<" --> ";
            for(auto z:x.second){   //Ek pair hai toh dhyaan rakhna syntax ka
                cout<<'('<<z.first<<','<<z.second<<')'<<" ";
            }
            cout<<endl;
        }
    }

    // Note - 1. For this algo, we will use 3 parameters - src,dest and number of nodes.
    //        2. We will use set(int for distance, U for temporary dest) and array(int for distance of temp node from src).
    //        3. process - source se explore karo har node and then waha se relaxation process ko follow karte destination par pahucho.

    void dijkstrasAlgo(U src, U dest, int noOfnodes){
        //Making a set - 
        //A set is a data structure that stores unique elements of the same type in a sorted order.
        // Note - Set mei pehle int hi store karo warna set ki property hamare hisaab se nhi chalegi shayad.
        set<pair<int,U>>s; //U is for temporary destination. Pair hai dhyaan rakhna

        //Making a distance array - 
        int distance[noOfnodes];

        // setting every initial value as infinity cause humme nhi pata konsa node src se kitni door hai?
        for(int i=0;i<noOfnodes;i++){
            distance[i]=INT_MAX;
        }

        distance[src]=0; //Src ka distance src se 0 hi hoga.
        s.insert({0,src}); //Src ka distance src se 0 hi hoga.
        
        while(!s.empty()){
            auto it=*(s.begin()); //Remember the inserting,using and deletion syntax for sets here.
            U tempKey1=it.second;
            int tempdist1=it.first; //distance of tempKey1 from given src.
            s.erase(it);

            for(auto x:h[tempKey1]){
                U tempKey2=x.first;
                int tempdist2=x.second; //EdgeWeight - distance of tempKey2 from tempKey1.

                //Relaxation Process - 
                if(tempdist1+tempdist2<distance[tempKey2]){

                    // erase if it existed, mtlb koi already uss node pe pahuch chuka hai
                    // and uska key,value pair bhi stored hai in the set, so delete that now 
                    // cause of ab kisi kaam ka nahi raha
                    if(distance[tempKey2]!=INT_MAX){
                        s.erase({distance[tempKey2],tempKey2});
                    }

                    distance[tempKey2]=tempdist1+tempdist2;
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
    g.dijkstrasAlgo(0,5,6);
    return 0;
}