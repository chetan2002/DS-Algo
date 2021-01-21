#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//*****************CLASS NODE******************************
class node{
public:
    ll data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};
//*****************CLASS NODE***************************************

//*****************INSERTION AT THE END******************************

node* insertAtEnd(node* &head , node* &tail , int data){
    if(head==nullptr){
        head = new node(data);
        tail = head;
        return head;
    }
    node* nn = new node(data);
    tail->next = nn;
    tail=nn;
    return head;
}

//*****************INSERTION AT THE END******************************


//*****************PRINT THE LL**************************************

void print(node* head){
    if(head==nullptr){
        return ;
    }
    cout<<head->data<<" ";
    print(head->next);
    return;;
}
//*****************PRINT THE LL*************************************


//*****************MERGE THE SORTED LL******************************

node* merge(node* head1 , node* head2){
	if(head1==nullptr){
		return head2;
	}
	if(head2 == nullptr){
		return head1;
	}
    node* head3 = nullptr;
    if(head1->data <= head2->data){
        head3 = head1;
        head1=head1->next;
    }else{
        head3 = head2;
        head2 = head2->next;
    }
    

    node* temp = head3;
    while(head1!=nullptr and head2!=nullptr){
        if(head1->data <= head2->data){
            temp->next = head1;
            head1=head1->next;
            temp = temp->next;
        }else{
            temp->next = head2;
            head2=head2->next;
            temp = temp->next;
        }
    }
    if(head1!=nullptr){
        temp->next = head1;
    }
    if(head2!=nullptr){
        temp->next = head2;
    }
    return head3;
}
//*****************MERGE THE SORTED LL******************************

//*****************LENGTH OF THE LL******************************
int length(node* head){
    if(head==nullptr){
        return 0;
    }
    return 1+length(head->next);
}
//*****************LENGTH OF THE LL******************************

//*****************Kth node from the last******************************
node* kthFromLast(node* head , int k){
    if(head==nullptr){
        return head;
    }
    node* slow = head;
    node* fast = head;
    for(int i=0;i<k;i++){
        fast = fast->next;
    }
    while(fast->next!=nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
//*****************Kth node from the last******************************

//****************  APPEND K LAST NODES TO BEGINNING*******************
node* appendKFromLastToBegin(node* &head1 , node* &tail1 , int k){
    node* val = kthFromLast(head1 , k);
    tail1->next = head1;
    head1 = val->next;
    val->next = nullptr;
    return head1;
}
//****************  APPEND K LAST NODES TO BEGINNING*******************

//**************** GROUP EVEN ODD *************************************
    node* groupEvenOdd(node* head){
        if(head==nullptr || head->next==nullptr || head->next->next == nullptr){
            return head;
        }
        node* odd = head;
        node* even = head->next;
        node* oddTemp = odd;
        node* evenTemp = even;
        while(odd!=nullptr && even!=nullptr){
            odd->next = even->next;
            odd = odd->next;
            if(odd!=nullptr){
                even->next = odd->next;
                even = even->next;
            }
            if(even!= nullptr and even->next == nullptr){
                break;
            }
        }
        odd->next = evenTemp;
        head = oddTemp;
        return head;
    }


//**************** GROUP EVEN ODD *************************************


int main(){
	
    int n;
    cin>>n;
    node* head = nullptr;
    node* tail = nullptr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        head = insertAtEnd(head , tail , val);
    }
    head = groupEvenOdd(head);
    print(head);
    return 0 ;
}