#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void print(vector<int> v) {
	for(auto c: v) {
		cout<<c<<" ";
	}
	cout<<endl;
}
vector<int> ans(int A) {
	    int mod = 1e9+7;
    vector<int> powerOfTwo;
    int val = 1;
    while(val<1e9+10) {
        powerOfTwo.push_back(val);
        val=val<<1;
    }
    vector<int> Jeff(A);
    Jeff[0]=1;
    for(int i=1;i<A;i++) {
        if(i==1) {
            Jeff[i]=1;
        }else{
            Jeff[i] = Jeff[i-1]+Jeff[i-2];
        }
    }
    print(Jeff);
    int n = A;
    vector<vector<int>> ans(n+1);
    for(int i=0;i<n;i++) {
        int pos = 0;
        int value = Jeff[i];
        while(value>0) {
            if(value%2==1){
                if(i+powerOfTwo[pos]<n){
                    ans[i+powerOfTwo[pos]].push_back(i);
                }
                if(i+powerOfTwo[pos+1]<n){
                    ans[i+powerOfTwo[pos+1]+1].push_back(-i);
                }
            }
            value/=2;
            pos++;
        }
    }
    vector<int> fin(n);
    fin[0] = 1;
    print(ans[0]);
    bool zeroOcc = false;
    for(int i=1;i<n;i++) {
    	print(ans[i]);
        long long int answer = (i==1)?0:fin[i-1];
        for(auto c: ans[i]) {
            if(c>0) {
                answer = (fin[c] + answer);
            }else{
            	if(!zeroOcc and c==0) {
            		answer++;
            		zeroOcc = true;
            		continue;
            	}else
            	if(c==0){
            		answer--;
            		continue;
            	}
                answer = answer-fin[-c];
            }
        }
        answer = answer % mod;
        fin[i] = answer;
    }
    return fin;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;
    cin>>a;
    vector<int> answer = ans(a);
    print(answer);
    return 0;
}