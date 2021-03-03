#include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <cmath>
#include<cstdlib>
#include<ctime>
#define ll long long
#define INF 100000000
using namespace std;

ll findMinCost(vector<int> &cost, vector<int> &weight, int n, int s)
{
    ll dp[s+1];
    dp[0]=0;
    for(int i=1;i<=s;i++){
        dp[i]=INF;
        for(int j=0;j<n;j++){
            if(weight[j]<=i){
                dp[i]=min(dp[i],dp[i-weight[j]]+cost[j]);
            }
        }
    }
    return dp[s]==INF?-1:dp[s];
}

ll answer(ll* arr , ll n , ll k){
	ll dp[10000];
	dp[0]=0;
	for(ll i=1;i<=k;i++){
		dp[i]=INT_MAX;
		for(ll j=1;j<=k;j++){
			if(i-j>=0 and arr[j-1]!=-1){
				dp[i] = min(dp[i] , dp[i-j]+arr[j-1]);	
			}
		}
		//cout<<dp[i]<<" ";
	}
	//cout<<endl;
	if(dp[k]==INT_MAX){
		return -1;
	}
	return dp[k];
}

int main(){
    srand(time(0));
    while(true){
        ll n, s;
        n = rand()%10+1;
        s = rand()%10;

        vector<int> cost;
        vector<int> weight;
        ll arr[s];
        for (int i = 0; i < s; i++)
        {
            int currcost;
            currcost = rand()%10;
            arr[i] = currcost;
            if (currcost != -1)
            {
                cost.push_back(currcost);
                weight.push_back(i + 1);
            }
        }
        ll val1 = findMinCost(cost, weight, cost.size(), s);
        ll val2 = answer(arr , n , s);
        if(val1==val2){
            cout<<"OK"<<endl;
            cout<<endl;
        }else{
            cout<<"Error! "<<endl;
            cout<<n<<" "<<s<<endl;
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<endl;
            break;
        }
    }
	return 0;
}