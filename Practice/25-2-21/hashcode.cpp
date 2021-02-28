#include<bits/stdc++.h>
using namespace std;
#define ll long long int


unordered_map<string , pair<ll,ll>> pairToNode;
unordered_map<string , ll> weights;
 
class graph{
public:
    unordered_map<ll , list<ll>> h;
    unordered_map<ll, ll> value;
    void addEdge(ll u , ll v ){
        h[u].push_back(v);
        value[v]++;
    }

};

int main(){
    ll duration, intersect, streets , cars , scorePoint;
    cin>>duration>>intersect>>streets>>cars>>scorePoint;
    graph g;
    for(ll i=0;i<streets;i++){
        ll u,v;
        cin>>u>>v;
        string s;
        cin>>s;
        ll wt;
        cin>>wt;
        pair<ll,ll> p;
        p.first = u;
        p.second = v;
        //nodetoPair.insert({p , s});
        pairToNode.insert({s , p});
        weights.insert({s , wt});
        g.addEdge(u,v);
    }

    vector<string> ans;
    for(ll i=0;i<cars;i++){
        int n;
        cin>>n;
        vector<string> v;
        int sum=0 , minVal = duration;
        for(int j=0;j<n;j++){
            string s;
            cin>>s;
            v.push_back(s);
            sum+=weights[s];
        }
        if(sum<duration){
            if(sum<minVal){
                minVal = sum;
                ans.clear();
                for(auto c: v){
                    ans.push_back(c);
                }
            }
        }

    }
    cout<<intersect<<endl;
    ll sum=1;
    vector<bool> vec(intersect , false);
    for(auto c: ans){
        sum += weights[c];
        int node = pairToNode[c].second;
        vec[node]=true;
        cout<<node<<endl;
        int count = 0;
        for(auto a: pairToNode){
            
            if(a.second.second==node){
                count++;
            }
        }
        cout<<count<<endl;
        for(auto a: pairToNode){
            if(a.first==c){
                continue;
            }
            if(a.second.second==node){
                cout<<a.first<<" "<<2<<endl;
            }
        }
        cout<<c<<" "<<sum<<endl;
    }
    for(int i=0;i<vec.size();i++){
        if(vec[i]!=true){
            int node = i;
            cout<<node<<endl;
            int count = 0;
            for(auto a: pairToNode){
                
                if(a.second.second==node){
                    count++;
                }
            }
            cout<<count<<endl;
            for(auto a: pairToNode){
                if(a.second.second==node){
                    cout<<a.first<<" "<<2<<endl;
                }
            }
        }
    }
    return 0;
}