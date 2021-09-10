#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int k=1;k<=t;k++){
    	ll n;cin>>n;
    	vector<string> myPersonalVector(n);
    	for(auto &it: myPersonalVector){
			cin>>it;    		
    	}

    	set<pair<ll,ll>> myPersonalMap;
    	ll minAnswer = 1000000;
    	ll occurance = 0;
    	for(int i=0;i<n;i++){
    		ll answerIFound = 0;
    		for(int j=0;j<n;j++){
    			if(myPersonalVector[i][j]=='.'){
    				answerIFound++;
    			}else
    			if(myPersonalVector[i][j]=='X'){
    				continue;
    			}else{
    				answerIFound = -1;
    				break;
    			}
    		}

    		if(answerIFound==-1){
    			continue;
    		}
    		if(answerIFound<minAnswer){
    			minAnswer = answerIFound;
    			occurance = 1;
    		}else
    		if(answerIFound == minAnswer){
    			occurance++;
    		}
    		if(answerIFound==1){
    			for(int j=0;j<n;j++){
	    			if(myPersonalVector[i][j]=='.'){
	    				myPersonalMap.insert({i,j});
	    			}
	    		}
    		}
    	}

    	for(int j=0;j<n;j++){
    		ll answerIFound = 0;
    		for(int i=0;i<n;i++){
    			if(myPersonalVector[i][j]=='.'){
    				answerIFound++;
    			}else
    			if(myPersonalVector[i][j]=='X'){
    				continue;
    			}else{
    				answerIFound = -1;
    				break;
    			}
    		}

    		if(answerIFound==-1){
    			continue;
    		}
    		if(answerIFound<minAnswer){
    			minAnswer = answerIFound;
    			occurance = 1;
    		}else
    		if(answerIFound == minAnswer){
    			occurance++;
    		}
    		if(answerIFound==1){
    			for(int i=0;i<n;i++){
	    			if(myPersonalVector[i][j]=='.'){
	    				myPersonalMap.insert({i,j});
	    			}
	    		}
    		}
    	}

    	if(minAnswer == 1000000){
	    	cout<<"Case #"<<k<<": "<<"Impossible"<<endl;
	    	continue;
    	}
    	if(minAnswer==1){
	    	cout<<"Case #"<<k<<": "<<1<<" "<<myPersonalMap.size()<<endl;			
	    	continue;
    	}
    	cout<<"Case #"<<k<<": "<<minAnswer<<" "<<occurance<<endl;
    }
    return 0;
}