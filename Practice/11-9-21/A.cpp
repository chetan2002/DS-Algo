#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h1 , h2 , m1 , m2;
    cin>>h1>>m1>>h2>>m2;
    
    int hh = min(24+h1-h2 , min(24+h2-h1 , abs(h1-h2)));
    int mm = min(60+m1-m2 , min(60+m2-m1 , abs(m1-m2)));
    cout<<hh+mm<<endl;
  return 0;
}