#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//*****************CLASS Node******************************
class Node{
public:
    ll value;
    Node* next;
    Node(int d){
        value = d;
        next = nullptr;
    }
};
//*****************CLASS Node***************************************

//*****************INSERTION AT THE END******************************

Node* insertAtEnd(Node* &head , Node* &tail , int value){
    if(head==nullptr){
        head = new Node(value);
        tail = head;
        return head;
    }
    Node* nn = new Node(value);
    tail->next = nn;
    tail=nn;
    return head;
}

//*****************INSERTION AT THE END******************************


//*****************PRINT THE LL**************************************

void print(Node* head){
    if(head==nullptr){
        return ;
    }
    cout<<head->value<<" ";
    print(head->next);
    return;;
}
//*****************PRINT THE LL*************************************


//REcursive reverse optimised 
Node* recursiveReverseOptimised(Node* head){
    if(head->next == NULL or head==NULL){
        return head;
    }
    Node* shead = recursiveReverseOptimised(head->next);

    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

Node* modify_list(Node* head){
    head = recursiveReverseOptimised(head);

    Node* temp = head;
    int carry = 0;
    Node* tail = head;
    while(temp!=nullptr){
        int val = temp->value*5 + carry;
        temp->value = val%10;
        carry = val/10;
        if(temp->next == nullptr){
            tail = temp;
        }
        temp = temp->next;
    }
    if(carry!=0){
        Node* nn = new Node(carry);
        tail->next = nn;
    }
    head = recursiveReverseOptimised(head);
    return head;
}

int main(){
	
    int n;
    cin>>n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        head = insertAtEnd(head , tail , val);
    }
    head = modify_list(head);
    print(head);
    return 0 ;
}