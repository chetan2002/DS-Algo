#include<bits/stdc++.h>
using namespace std;
int cap=1000;
class Stack{
public:
	int top;
	int *arr;
	Stack(){
		top=0;
		arr = new int[cap];
		for(int i=0;i<cap;i++){
			arr[i]=0;
		}
	}
	void push(int data);
	void pop();		
	bool isEmpty();
	int topa();
	// void print();

};
void Stack::push(int data){
	arr[top++]=data;
}
void Stack::pop(){
	top--;
}
bool Stack::isEmpty(){
	if(top==0){
		return true;
	}
	return false;
}
int Stack::topa(){
	if(!isEmpty){
		int x=arr[top]
		return x;
	}
}
void Stack::print(){
	while(top!=0){
		cout<<arr[top]<<" ";
		top--;
	}
}
int main(){
	// Stack s;
	int n;
	cin>>n;
	cout<<n<<endl;
	// for(int i=0;i<n;i++){
	// 	int el;
	// 	cin>>el;
	// 	cout<<el<<" ";
	// 	// s.push(el);
	// }
	// cout<<s.topa()<<endl;
	// s.print();
	return 0;
}