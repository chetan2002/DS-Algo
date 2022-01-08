#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &c: v) {
        cin>>c;
    }
    vector<ll> left(n);
    vector<ll> right(n);
    stack<ll> s;
    s.push(0);
    for(int i=1; i<n; i++) {
    	while(!s.empty() and v[s.top()]>=v[i]) {
    		s.pop();
    	}
    	if(s.empty()) {
    		left[i] = i*v[i];
    	}else {
    		left[i] = (i-s.top()-1)*v[i] + left[s.top()] + v[s.top()];
    	}
    	s.push(i);
    }
    while(!s.empty()) {
    	s.pop();
    }
    s.push(n-1);
    for(int i=n-2; i>=0; i--) {
    	while(!s.empty() and v[s.top()]>=v[i]) {
    		s.pop();
    	}
    	if(s.empty()) {
    		right[i] = (n-1-i)*v[i];
    	}else {
    		right[i] = (s.top()-i-1)*v[i] + (right[s.top()] + v[s.top()]);
    	}
    	s.push(i);
    }
    ll maxi = 0, maxiInd = 0;
    for(int i=0; i<n; i++) {
    	if(left[i]+right[i]+v[i] > maxi) {
    		maxi = left[i]+right[i]+v[i];
    		maxiInd = i;
    	}
    }
    ll leftMin = v[maxiInd];
    vector<ll> ans(n);
    for(int j=maxiInd-1; j>=0; j--) {
        leftMin = min(leftMin, v[j]);
        ans[j] = leftMin;
    }
    ll rightMin = v[maxiInd];
    for(int j=maxiInd+1; j<n; j++) {
        rightMin = min(rightMin, v[j]);
        ans[j] = rightMin;
    }
    ans[maxiInd] = v[maxiInd];
    for(auto c: ans) {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}