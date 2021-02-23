#include<iostream>
#include<list>
#include<unordered_map>
#include<string>
using namespace std;


template<typename T>
class Graph{
public:
    unordered_map<T , list<T>> h;

    void addEdge(T u , T v , bool bidir = false){
        h[u].push_back(v);
        if(bidir){
            h[v].push_back(u);
        }
    }

    void print(){
        for(auto c: h){
            cout<< c.first << ": ";
            for(auto a : c.second){
                cout<< a << " ";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    Graph<string> g;

    g.addEdge("Putin" , "Trump");
    g.addEdge("Putin" , "Modi");
    g.addEdge("Putin" , "Pope");
    g.addEdge("Modi" , "Trump" , true);
    g.addEdge("Modi" , "Yogi" , true);
    g.addEdge("Yogi" , "Prabhu");
    g.addEdge("Prabhu" , "Modi");

    return 0;

}
