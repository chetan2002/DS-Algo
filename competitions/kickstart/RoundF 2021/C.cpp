#include<bits/stdc++.h>
using namespace std;
#define ll long long int


float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool isInsideTri(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   float A = area (x1, y1, x2, y2, x3, y3);
   float A1 = area (x, y, x2, y2, x3, y3);
   float A2 = area (x1, y1, x, y, x3, y3);
   float A3 = area (x1, y1, x2, y2, x, y);
   if(A==0 || A1==0 || A2 == 0 || A3 == 0 ) {
   		return false;
   }
   return (A == A1 + A2 + A3);
}

bool isInsideQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x, int y)
{  
   float A = area (x1, y1, x2, y2, x3, y3) + area(x1, y1, x3, y3, x4, y4);
   float A1 = area (x, y, x2, y2, x3, y3);
   float A2 = area (x1, y1, x, y, x4, y4);
   float A3 = area (x1, y1, x2, y2, x, y);
   float A4 = area (x, y, x4, y4, x3, y3);

   if(A==0 || A1==0 || A2 == 0 || A3 == 0 || A4==0) {
   		return false;
   }
   return (A == A1 + A2 + A3 + A4);
}

double length(double x1, double y1 , double x2,  double y2) {
	double ans = (x2-x1)*(x2-x1)  + (y2-y1)*(y2-y1);
	ans = sqrt(ans);
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
    	ll n;
    	cin>>n;
    	cout.precision(17);
    	vector<pair<double,double>> vp(n);
    	sort(vp.begin(), vp.end());
    	for(auto &c: vp) {
    		cin>>c.first;
    		cin>>c.second;
    	}
    	double xi, yi;
    	cin>>xi>>yi;
    	double mini = 10000000;
    	for(int i=0;i<n;i++) {
    		for(int j=i+1;j<n;j++) {
    			for(int k=j+1;j<n;j++) {
    				if(isInsideTri(vp[i].first, vp[i].second, vp[j].first, vp[j].second, vp[k].first, vp[k].second, xi, yi)) {
    					double answer = length(vp[i].first, vp[i].second, vp[j].first, vp[j].second) + length(vp[j].first, vp[j].second, vp[k].first, vp[k].second) + length(vp[i].first, vp[i].second, vp[k].first, vp[k].second);
    					mini = min(mini, answer);

    				}
    			}
    		}
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=i+1;j<n;j++) {
    			for(int k=j+1;j<n;j++) {
    				for(int l = k+1; l<n; l++) {
    					
						if(isInsideQuad(vp[i].first, vp[i].second, vp[j].first, vp[j].second, vp[l].first, vp[l].second, vp[k].first, vp[k].second , xi, yi)) {
	    					double answer = length(vp[i].first, vp[i].second, vp[j].first, vp[j].second) + length(vp[j].first, vp[j].second, vp[l].first, vp[l].second) + length(vp[k].first, vp[k].second, vp[l].first, vp[l].second) + length(vp[k].first, vp[k].second, vp[i].first, vp[i].second);
	    					mini = min(mini, answer);
	    				}
    				}
				
    			}
    		}
    	}
    	double count = mini;
    	if(mini == 10000000) {
    		cout<<"Case #"<<l<<": "<<"IMPOSSIBLE"<<endl;	
    		continue;
    	}
    	cout<<"Case #"<<l<<": "<<count<<endl;
    }
    return 0;
}