#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Node{
	public:
		ll val;
		Node* next;
		Node(int d){
			val = d;
			next = nullptr;
		}
};

Node* insertAtEnd(Node* &head , Node* &tail , int d){
	if(head == nullptr){
		head = new Node(d);
		tail = head;
		return head;
	}
	Node* n = new Node(d);
	tail->next = n;
	tail = tail->next;
	return head;
}

void print(Node* head){
	if(head == nullptr){
		return ;
	}
	cout<<head->val<<" ";
	print(head->next);
}


Node* mergeTwoSortedLL(Node* a , Node* b){
	if(a == nullptr){
		return b;
	}
	if(b == nullptr){
		return a;
	}
	Node* head = nullptr;

	if(a->val < b->val){
		head = a;
		a = a->next;
	}else{
		head = b;
		b = b->next;
	}
	Node* temp = head;
	while(a!= nullptr and b!= nullptr){
		if(a->val < b->val){
			temp->next = a;
			a = a->next;
		}else{
			temp->next = b;
			b = b->next;
		}
		temp = temp->next;
	}
	if(a!=nullptr){
		temp->next = a;
	}
	if(b!=nullptr){
		temp->next = b;
	}
	return head;
}

Node* mergeSortedLL(Node** arr , int n){
	Node* head = nullptr;
	for(int i=0;i<n;i++){
		head = mergeTwoSortedLL(arr[i] , head);
	}
	return head;
}


int main(){
	ll n , m;
	cin>>n>>m;
	Node* arr[n];
	for(int i = 0;i<n;i++){
		Node* head1 = nullptr;
		Node* tail1 = nullptr;
		for(int j = 0 ;j<m ;j++){
			ll d;
			cin>>d;
			insertAtEnd(head1 , tail1 , d);
		}
		arr[i] = head1;
	}
	Node* head = mergeSortedLL(arr , n);
	print(head);
	return 0;
}


//TC
// 3 4
// 5 5 5 9 3 13 14 17 1 8 11 18 


//Ans
//1 3 5 5 5 8 9 11 13 14 17 18 