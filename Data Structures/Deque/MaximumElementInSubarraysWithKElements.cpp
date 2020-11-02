#include <iostream>
#include<deque>
#include<vector>
using namespace std;

//In this question , we have to calculate the maximum element of all subarrays with k elements in the array
//It can be solved using brute force 
//But this approach uses the SLIDING-WINDOW APPROACH



void maximumElementInRangeK(vector<int> v , int n , int k){

    //intialize a deque
    deque<int> q;

    //first find elements to put in deque for first k element
    int i=0;
    for(;i<k;i++){

        //if element of back of deque is smaller than the current element then pop
        while(!q.empty() && v[i]>v[q.back()]){
            q.pop_back();
        }

        //push the current element
        q.push_back(i);
    }

    //for windows after first k elements
    for(;i<n;i++){
        //print the first element of deque
        cout<<v[q.front()]<<" ";

        //if element of back of deque is smaller than the current element then pop
        while(!q.empty() && v[i]>v[q.back()]){
            q.pop_back();
        }

        //if front element of deque is smaller than the window then pop
        while(!q.empty() && q.front()<=(i-k)){
            q.pop_front();
        }

        //push the current element
        q.push_back(i);
    }

    //for the last window
    cout<<v[q.front()]<<endl;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;

    //input elements
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }

    //input size of window
    int k;
    cin>>k;

    maximumElementInRangeK(v , n , k);
    
    return 0;
}
