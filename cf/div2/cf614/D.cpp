#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(ll pos , vector<pair<ll,ll>> vp , ll t , vector<bool> vis , ll count){
	if(t<0){
		return 0;
	}

	int last = pos;
	for(int i=pos;i<vp.size();i++){
 		if(vis[i]!=true){
 			ll val = abs(vp[i].first-vp[last].first)+abs(vp[i].second-vp[last].second); 		
 			if(t>=val){
 				t-=val;count++;
 				vis[i]=true;
 			}else{
 				t-=val;
 				break;
 			}
 			if(t<0){
 				break;
 			}
 			last = i;
 		}
 	}
 	return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll x0 , y0 , ax , ay , bx , by , xs , ys , t;
 	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;

 	vector<pair<ll,ll>> vp;
 	vp.push_back({x0,y0});
 	ll limit  = (1LL << 62) -1;
 	for(int i=1;i<70;i++){
 		ll val1 = ax*(vp[i-1].first)+bx;
 		ll val2 = ay*(vp[i-1].second)+by;

 	
 		vp.push_back({val1 , val2});
 		// cout<<val1<<" "<<val2<<endl;

 		if(val1> (limit-bx)/ax || val2>(limit-by)/ay){
 			break;
 		}

 	}   

 	ll maxi = 0 ;
 	ll count = 0;
 	if(find(vp.begin() , vp.end(),make_pair(xs,ys))!=vp.end()){
 		count++;
 	}else{
 		vp.push_back({xs,ys});
 		sort(vp.begin(),vp.end());
 	}

 	int pos = 0;
 	for(int i=0;i<vp.size();i++){
 		if(vp[i]==make_pair(xs,ys)){
 			pos = i;
 			break;
 		}
 	}

 	vector<bool> vis(vp.size(),false);
 	vis[pos] = true;
 	for(int i=pos;i>=0;i--){
 		if(vis[i]!=true){
 			ll val = abs(vp[i].first-vp[i+1].first)+abs(vp[i].second-vp[i+1].second); 		
 			if(t>=val){
 				t-=val;count++;
 				vis[i]=true;
 			}else{
 				t-=val;
 			}
 		}
 		if(t<0){
 			break;
 		}
 		ll value = 0;
 		if(t>0){
	 		value =answer(i,vp , t , vis , count);
 		}
 		maxi = max(value , max(count , maxi));
 	}
 	cout<<maxi<<endl;

    return 0;
}