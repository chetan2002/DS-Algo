#include<iostream>
#include<list>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;


template<typename T>
class Graph{
public:
    unordered_map<T , list<T>> h;

    void addEdge(T u , T v , bool bidir = true){
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

    //breadth first search
    void bfs(T start){
        queue<T> q;
        unordered_map<T , bool> visited;
        q.push(start);
        visited[start]=true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto child: h[node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]= true;
                }
            }
        }
        cout<<endl;
    }
    //distance between 2 nodes
    //single source shortest path algorithm
    int DistanceNodes(T start , T end){
        queue<T> q;
        unordered_map<T , bool> visited;
        q.push(start);
        visited[start]=true;
        unordered_map<T , int> distance;
        unordered_map<T , T> parent;
        distance[start] = 0;
        parent[start] = start;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            // cout<<node<<" ";
            for(auto child: h[node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]= true;
                    distance[child] = distance[node]+1;
                    parent[child] = node;
                }
            }
        }
        // cout<<endl<<"Distance from start"<<endl;
        // for(auto c: distance){
        //     cout<<start<<"->"<<c.first<<" : "<<c.second<<endl;
        // }

        //print path
        cout<<"Path from "<<start<<" to "<<end<<endl;
        T temp = end;
        while(temp != parent[temp]){
            cout<< temp <<"<--";
            temp = parent[temp];
        }
        cout<<temp<<endl;
        return distance[end];
    }
    //depthfirstSearch

    void dfsHelper(T start , unordered_map<T, bool > &visited){
        visited[start] = true;
        cout<<start<< " " ;

        for(auto child: h[start]){
            if(!visited[child]){
                dfsHelper(child , visited);
            }
        }
    }
    void dfs(T src){
        int components = 1;
        unordered_map<T, bool> visited;
        dfsHelper(src , visited);

        for(auto node: h){
            if(!visited[node.first]){
                components++;
                dfsHelper(node.first , visited);
            }
        }
        cout<<endl<<"Total Components are : "<<endl;
        cout<<components<<endl;
    }
};

int main(){
    
    int no_of_edges , no_of_nodes;
    cin>>no_of_edges>>no_of_nodes;


    Graph<int> g;

    int u,v;
    for(int i=0;i<no_of_nodes;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }

   // g.print();
    // g.bfs(0);
    // int minDis = g.DistanceNodes(0,5);
    // cout<<"Distance bw "<<0<<" and "<<5<<" = "<<minDis<<endl;

    g.dfs(0);

    return 0;

}




// 6 7 
// 1 0 
// 0 4
// 4 2
// 2 1
// 2 3
// 3 4
// 3 5
