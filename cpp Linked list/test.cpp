#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void insertAtAnyPosition(node* &head,int val,int pos){
    node* n=new node(val);
    if(head==NULL){
        cout<<"Addition not possible.";
    }
    node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    n->data=val;
    n->next=temp->next;
    temp->next=n;
}
void insertAtAnyPoint(node* & head,int val,int pos){
    node* n=new node(val);
    if(head==NULL){
        cout<<"Not Possible";
    }
    node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;       
    }
    n->data=val;
    n->next=temp->next;
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}




