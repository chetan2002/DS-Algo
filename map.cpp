#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

struct comp{
    bool operator()(auto a , auto b){
        return a>b;
    }
};

bool mapcomp(auto a , auto b){
    return a<b;
}
int main(){
    map<int,int , comp> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        mp[val]++;
    }

    sort(mp.begin() , mp.end() , mapcomp);
    for(auto c: mp){
        cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}