#include<bits/stdc++.h>
using namespace std;

class Minheap{
private:
    void heapify(int i){
        int min_index = i;
        int left = 2*i;
        int right = left+1; //(2*i +1);

        if(left<v.size() and v[min_index]>v[left]){
            //if value of left is smaller than the current min_index
            min_index = left;
        }
        if(right<v.size() and v[min_index]>v[right]){
            min_index = right;
        }

        if(min_index != i){
            swap(v[min_index] , v[i]);
            heapify(min_index ) ;

        }


    }
public:
    vector<int> v;
    Minheap(){
        v.push_back(-1);    //done bcz we want to avoid 0th index
    }

    void push(int d){
        v.push_back(d);
        int c = v.size()-1;
        int p = c/2;
        
        while(c>1 and v[p]>v[c]){
            swap(v[p] , v[c]);
            c = p;
            p /=2 ;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        swap(v[1] , v[v.size()-1]);
        v.pop_back();

        heapify(1);
    }

    bool empty(){
        return (v.size()==1);
    }
};

int main(){
    Minheap h;
    int n;
    cin>>n;
    for(int i=0 ; i<n;i++){
        int val;
        cin>>val;
        h.push(val);
    }
    
    for(int i=0; i<n;i++){
        int val = h.top();
        h.pop();
        cout<<val<<" ";
    }
    while (!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    
    return 0;
}