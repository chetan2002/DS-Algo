#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

template<typename T>
class Graph{
    unordered_map<T , list<pair<T , int> > > h;
public: 

    void addEdge(T src , T des , int dist , bool bidir = true ){
        h[src].push_back({des , dist});
        if(bidir){
            h[des].push_back({src , dist});
        }
    }
    
};