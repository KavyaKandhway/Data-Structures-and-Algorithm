#include <bits/stdc++.h>
using namespace std;
class Nodecll {
public:
    int data;
    Nodecll* next;
};
struct Nodedll {
    int data;
    struct Nodedll* next, *prev;
};
void insert(struct Nodedll** head, int data)
{
    struct Nodedll* temp = new Nodedll();
 
    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
void push(Nodecll** head_ref, int data)
{
    Nodecll* ptr1 = new Nodecll();
    ptr1->data = data;
    ptr1->next = *head_ref;
    if (*head_ref != NULL) 
    {
        Nodecll* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
  
    *head_ref = ptr1;
}

void printList(Nodecll* head)
{
    Nodecll* temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
  
    cout << endl;
}
 
void deleteNode(Nodecll** head, int key) 
{
	if(*head==NULL){
		return;
	}
	if((*head)->next==(*head)){
		if((*head)->data==key){
			*head=NULL;
		}
		return ;
	}
	Nodecll* cur=*head;
	Nodecll* prev;
	if(cur->data==key){
		prev=cur;
		while(prev->next!=*head){
			prev=prev->next;
		}
		cout<<prev->data<<endl;
		prev->next=cur->next;
		*head=cur->next;
		cout<<(*head)->data<<endl;
		return;
	}
	while(cur->next!=*head){
		if(cur->data!=key){
			prev=cur;
			cur=cur->next;
			
			continue;
		}
		
		prev->next=cur->next;
		return;
	}
	if(cur->data==key){
		prev->next=*head;
	}
	return;
}
int countTriplets(Nodedll* head,int x){
	int ans=0;
	if(!head||!head->next||!head->next->next){
		return 0;
	}
	Nodedll* i=head;
	for(i=head;i!=NULL;i=i->next){
		int val=x-i->data;
		if(!i->next)break;
		if(!i->next->next)break;
		Nodedll* j=i->next;
		Nodedll* k=j->next;
		while(k->next!=NULL){
			k=k->next;
		}
		while(j && k && j!=k ){
			int cur=j->data+k->data;
			if(cur==val){
				ans++;
				j=j->next;
				
			}else if(cur>val){
				k=k->prev;
			}else{
				j=j->next;
			}
		}
	}
	return ans;
}
int main()
{
    Nodedll* head = NULL;
  
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
 
    int x = 17;
 
    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}