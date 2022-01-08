#include<bits/stdc++.h>
using namespace std;
#define ll long long int
multiset<ll, greater<ll>> leftSet;
multiset<ll> rightSet;
ll sumL = 0, sumR = 0;

// shift the top element from left to right set
void leftToRight() {
    rightSet.insert(*leftSet.begin());
    sumR += *leftSet.begin();
    sumL -= *leftSet.begin();
    leftSet.erase(leftSet.begin());
}

// shift the top element from right to left set
void rightToLeft() {
    leftSet.insert(*rightSet.begin());
    sumL += *rightSet.begin();
    sumR -= *rightSet.begin();
    rightSet.erase(rightSet.begin());
}

// insert element in set
void insert(ll val) {
    leftSet.insert(val);
    sumL += val;
    leftToRight();

    if(rightSet.size()>leftSet.size()) {
        rightToLeft();
    }
}

// remove element from set
void remove(ll val) {
    if(leftSet.find(val)!=leftSet.end()) {
        if(leftSet.size()<=rightSet.size()) {
            rightToLeft();
        }
        leftSet.erase(leftSet.find(val));
        sumL-=val;
    }else
    if(rightSet.find(val)!=rightSet.end()) {
        if(rightSet.size()<leftSet.size()){ 
            leftToRight();
        }
        rightSet.erase(rightSet.find(val));
        sumR-=val;
    }
}

// calculate answer
ll calculate() {
    ll med = *leftSet.begin();
    if(rightSet.size()==leftSet.size()) {
        med = (med + *rightSet.begin())/2;
    }
    ll answer = ((ll)leftSet.size())*med - sumL + (sumR - ((ll)rightSet.size())*med);
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;
 	vector<ll> v(n);
    for(auto &c: v) {
        cin>>c;
    }
    leftSet.clear(), rightSet.clear(), sumL = 0, sumR =0;
    for(int i=0; i<k; i++) {
        insert(v[i]);
    }
    cout<<calculate()<<" ";
    for(int i=k; i<n; i++) {
        remove(v[i-k]);
        insert(v[i]);
        cout<<calculate()<<" ";
    }
    cout<<endl;
    return 0;
}

