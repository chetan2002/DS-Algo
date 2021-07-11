#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n,k;cin>>n>>k;

 	ordered_set s;
    for(int i=0;i<n;i++){
        s.insert(i+1);
    }

    int pos = 0;
    while(s.size()>1){
        pos = (pos+k)%(int)s.size();
        auto it = s.find_by_order(pos);
        cout<<*it<<" ";
        s.erase(it);
        pos = pos%(int)(s.size());
    }
    cout<<*s.find_by_order(0)<<endl;
    return 0;
}