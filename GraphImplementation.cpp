#include<iostream>
#include<list>
using namespace std;

class Graph{
public: 
    list<int> *l;
    int n;
    Graph(int N){
        l = new list<int>[N];
        n = N;
    }

    void addEdge(int u , int v , bool bidir = true){
        l[u].push_back(v);

        if(bidir){
            l[v].push_back(u);
        }
    }

    void print(){
        for(auto i : l){
            // cout<<i<<":";
            for(auto c: i){
                cout<<c<<"-->";
            }
            cout<<endl;
        }
    }

};

int main(){
    int no_of_edges , no_of_nodes;
    cin>>no_of_edges>>no_of_nodes;


    Graph g(no_of_nodes);

    int u,v;
    for(int i=0;i<no_of_edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }

    g.print();

    cout<<endl;
    return 0;
}