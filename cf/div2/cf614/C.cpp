#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, q;
    cin>>n>>q;
	unordered_set<pair<int,int> , pair_hash> s;

	int blockCount = 0;
    while(q--){
    	int a , b;
    	cin>>a>>b;
    	if(s.find({a,b})!=s.end()){
    		s.erase({a,b});
    		if(a==1){
    			if(s.find({a+1,b})!=s.end()){
    				blockCount--;
    			}
    			if(s.find({a+1,b-1})!=s.end()){
    				blockCount--;
    			}
    			if(s.find({a+1,b+1})!=s.end()){
    				blockCount--;
    			}
    		}else{

    			if(s.find({a-1,b})!=s.end()){
    				blockCount--;
    			}
    			if(s.find({a-1,b-1})!=s.end()){
    				blockCount--;
    			}
    			if(s.find({a-1,b+1})!=s.end()){
    				blockCount--;
    			}
    		}
    	}else{
    		s.insert({a,b});
    		if(a==1){
    			if(s.find({a+1,b})!=s.end()){
    				blockCount++;
    			}
    			if(s.find({a+1,b-1})!=s.end()){
    				blockCount++;
    			}
    			if(s.find({a+1,b+1})!=s.end()){
    				blockCount++;
    			}
    		}else{

    			if(s.find({a-1,b})!=s.end()){
    				blockCount++;
    			}
    			if(s.find({a-1,b-1})!=s.end()){
    				blockCount++;
    			}
    			if(s.find({a-1,b+1})!=s.end()){
    				blockCount++;
    			}
    		}
    	}
    	if(s.size()==1){
    		cout<<"YES"<<endl;
    	}else{

    		
    		if(blockCount==0){
    			cout<<"YES"<<endl;
    		}else{
    			cout<<"NO"<<endl;
    		}
    	}
    }

    return 0;
}