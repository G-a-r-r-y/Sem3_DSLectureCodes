
//Graph Adjaceny List Representation Using Hash-map 
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename U>

class graph{
    unordered_map<U,list<U>>h;  //Generic Type

    //This covers all -
    // unordered_map<string,list<string> >h;
	// unordered_map<int,list<int> >h;
	// map<int,list<int> >h;

    // In this case since humne sirf 1 type of generic dataType define kiya hai,i.e U
    // toh array ka dataType and list ka dataType will be same.

    //Note - No constructor needed for this case cause hume size of array define karne 
    //       ki koi zarurat nhi hai.

    public:
    void addEdge(U x,U y, bool isBidirectional=false){
        h[x].push_back(y);
        if(isBidirectional==true){
            h[y].push_back(x);
        }
    }
    
    //Note - A graph can have multiple components(disconnected links with a graph)
    void printGraph(){
        for(auto x:h){ 
            cout<<x.first<<"---->"; 
            for(auto z:x.second){
                cout<<z<<" ";
            }
            cout<<endl;
        }
    }
    // Note - Arrangement of data in h -> {(key1,values1(list)),(key2,values2(list)),(key3,values3(list)).....}
    //        Therefore x corresponds to (key1,values1(list)). 
    //                  x.first corresponds to key1.
    //                  x.second corresponds to values1 which is a list.
    //                  and z corresponds to each element in x.second which is a list.
};

int main(){

    //Note - for generic type, we have to define the type of data which will replace U(generic dataType)
    //       during object creation.

    // Call karte waqt U define karna hota hai.
    graph<int> gI;
	gI.addEdge(0,1);
	gI.addEdge(0,4);
	gI.addEdge(1,4);
	gI.addEdge(1,3);
	gI.addEdge(4,3);
	gI.addEdge(1,2);
	gI.addEdge(2,3);
    cout<<"Integer Type Graph - "<<endl;
    gI.printGraph();
    cout<<endl;

    graph<string>gS;
	gS.addEdge("putin","trump");
	gS.addEdge("putin","modi");
	gS.addEdge("putin","pope");
	gS.addEdge("modi","trump");
	gS.addEdge("modi","yogi");
	gS.addEdge("prabhu","modi");
	gS.addEdge("yogi","prabhu");
    cout<<"String Type Graph - "<<endl;
    gS.printGraph();
    return 0;
}

