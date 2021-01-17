#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int d){
            data=d;
            next = nullptr;
        }
};


//finding length of linkedlist
int length(const Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}


//Printting the linkedlist
void print(const Node* head){
    if(head==nullptr){
        return;
    }
    while(head->next!=nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    if(head!=nullptr){
        cout<<head->data<<endl;
        head=head->next;
    }
}

//INserting elements in Linkedlist
//Inserting at head
void insertAtHead(Node* &head , int d){
    if(head==NULL){
        head=new Node(d);
        return;
    }
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}



//Inserting at end
void insertAtTail(Node* &head , int d){
    if(head==nullptr){
        head = new Node(d);
        return ;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;

    }
    Node* n = new Node(d);
    temp->next = n;
}

//Inserting in middle
void insertInMiddle(Node* &head , int d , int p){
    if(head==NULL || p==0){
        insertAtHead(head , d);
    }else
    if(p>length(head)){
        insertAtTail(head, d);
    }else{
        //take p-1 steps
        int jump = 1 ; 
        Node* temp = head ; 
        while(jump<p){
            temp = temp->next;
            jump++;
        }
        Node* n  = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }

}

Node* sumLL(Node* head1 , Node* head2){
	if(head1==nullptr){
		return head2;
	}
	if(head2==nullptr){
		return head1;
	}
	Node* head3 = nullptr;
	int carry = 0 ;
	int sum = head1->data + head2->data;
	Node* nn = new Node(sum%10);
	
	carry = sum/10;
	Node* temp = head3;
	head1=head1->next;
	head2 = head2->next;
	while(head1!=nullptr and head2!=nullptr){
		sum = head1->data + head2->data + carry;
		nn = new Node(sum%10);
		carry=sum/10;
		temp->next = nn;
		temp=temp->next;
		head1=head1->next;
		head2 = head2->next;
	}
	while(head1!=nullptr){
		sum = head1->data +carry;
		nn = new Node(sum%10);
		carry=sum/10;
		temp->next = nn;
		temp=temp->next;
		head1=head1->next;
	}
	while(head2!=nullptr){
		sum = head2->data + carry;
		nn = new Node(sum%10);
		carry=sum/10;
		temp->next = nn;
		temp=temp->next;
		head2 = head2->next;
	}
	if(carry!=0){
		nn = new Node(carry);
		temp->next = nn;
	}
	return head3;
}

void printRev(Node* head){
	if(head==nullptr){
		return ;
	}
	int val = head->data;
	printRev(head->next);
	cout<<val<<" ";
}
int main(){
	int n1 , n2;
	cin>>n1>>n2;
	Node* head1 = nullptr;
	for(int i=0;i<n1;i++){
		int val;
		cin>>val;
		insertAtHead(head1 , val);
	}
	Node* head2 = nullptr;
	for(int i=0;i<n1;i++){
		int val;
		cin>>val;
		insertAtHead(head2 , val);
	}

	Node* head3 = sumLL(head1 , head2);
	printRev(head3);
	return 0 ;
}