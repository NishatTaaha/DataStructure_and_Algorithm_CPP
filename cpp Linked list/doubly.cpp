#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void insertAnyPosition(node* &head,int val,int pos){
    node* n=new node(val);
    node* temp=head;
    node* position=temp->next;
    if(head==NULL || pos==1){
        insertAtHead(head,val);
        return;
    }
    int count=2;
    while(count!=pos){
       temp=temp->next;
        if(temp->next==NULL){
        insertAtTail(head,val);
        return;
    }
    position=position->next;
    count++;
    }
    temp->next=n;
    n->prev=temp;
    n->next=position;
    position->prev=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<""<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void deletion(node* & head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->next;
    }
    delete temp;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAnyPosition(head,5,8);
    insertAnyPosition(head,8,7);
    display(head);
    deleteAtHead(head);
    display(head);
    deletion(head,3);
    display(head);
}
