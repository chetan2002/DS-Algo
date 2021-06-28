#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	double x;
    	cin>>n>>x;

    	vector<double> v(n);
    	for(auto &c: v){
    		cin>>c;
    	}
    	sort(v.begin(),v.end(),greater<int>());;
    	int count = 0;
    	double sum =0 ;
    	for(auto c: v){
    		sum+=c;
    		if(sum/(count+1)>=x){
    			count++;
    		}else{
    			break;
    		}
    	}
    	// priority_queue<double> losers;
    	// priority_queue<double, vector<double> , greater<double>> winners;
    	// ll count = 0;
    	// for(auto c: v){
    	// 	if(c>x){
    	// 		winners.push(c);
    	// 	}else
    	// 	if(c<x){
    	// 		losers.push(c);
    	// 	}else{
    	// 		count++;
    	// 	}
    	// }
    	// while(!losers.empty() and !winners.empty()){
    	// 	double a1 = losers.top();
    	// 	losers.pop();
    	// 	double a2 = winners.top();
    	// 	winners.pop();
    	// 	double value = (a1+a2)/2;
    	// 	if(value==x){
    	// 		count+=2;
    	// 		continue;
    	// 	}else
    	// 	if(value>x){
    	// 		winners.push(value);
    	// 		winners.push(value);
    	// 		count = max((ll)winners.size(),count);
    	// 	}else{
    	// 		if(v.size()!=1){
    	// 			count = max((ll)winners.size(),count);
    	// 			losers.push(value);
    	// 			losers.push(value);
    	// 		}else{
    	// 			count++;
    	// 		}
     //   		}
    	// }
    	cout<<count<<endl;
    }
    return 0;
}