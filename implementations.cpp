// Implementations

#include<bits/stdc++.h>
using namespace std;

//Stack Using Queue
class Stack_usingQueue{
	public:
	queue<int> q1,q2;
	
	// pop all items from q1 and push them to q2
	// push new element in q1
	// push all items of q2 to q1
	void push(int x)   //O(n)
	{
		while(!q1.empty()){
			int t=q1.front();
			q1.pop();
			q2.push(t);
		}
		q1.push(x);
		while(!q2.empty()){
			int t=q2.front();
			q2.pop();
			q1.push(t);
		}
		return;
	}
	int pop() //O(1)
	{
		int t=q1.front();
		q1.pop();
		return t;
	}
};


//Queue using stack
class Queue_usingStack{
	public:
	stack<int> s1,s2;
	// push all elements from s1 to s2
	// push new in s1
	// push all elements from s2 to s1 again
	void push(int x){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		return;
	}
	int pop(){
		int t=s1.top();
		s1.pop();
		return t;
	}
};
//helpers
class Node{
	public:
	Node* next;
	int data;
	Node(int data){
		next=NULL;
		this->data=data;
	}
};


//Stack Using LinkedList
class Stack_usingLL{
	public:
	Node *head;
	Stack_usingLL(){
		head=NULL;
	}
	void push(int x){
		Node* temp=new Node(x);
		if(head==NULL){
			head=temp;
			head->next=NULL;
		}
		else{
			temp->next=head;
			head=temp;
		}
		
	}
	int pop(){
		Node* temp=head;
		head=temp->next;
		int val=temp->data;
		delete(temp);
		return val;
	}
};

//Queue using LinkedList
class Queue_usingLL{
	public:
	Node* front;
	Node* rear;
	Queue_usingLL(){
		front=NULL;
		rear=NULL;
	}
	void push(int x){
		Node* temp=new Node(x);
		if(front==NULL){
			front=temp;
			rear=temp;
		}else{
			rear->next=temp;
			rear=rear->next;
		}
	}
	int pop(){
		Node* temp=front;
		int val=front->data;
		front=front->next;
		delete(temp);
		return val;
	}
};
int main(){
	Stack_usingQueue st=Stack_usingQueue();
	Queue_usingStack qu=Queue_usingStack();
	Stack_usingLL sll=Stack_usingLL();
	Queue_usingLL qll=Queue_usingLL();
	
}