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
void display(node* head){ 
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void mergeLL(node* first, node* second){
    node* firstRef=first;
    while(firstRef->next!=NULL){
        firstRef=firstRef->next;
    }
    firstRef->next=second;
}
int main(){
    node *first=NULL, *second=NULL;
    insertAtTail(first,1),    
    insertAtTail(first,2);
    insertAtTail(first,3);
    insertAtTail(first,4);
    cout<<"First LinkedList: ";
    display(first);
    cout<<endl;
    insertAtTail(second,5),    
    insertAtTail(second,6);
    insertAtTail(second,7);
    insertAtTail(second,8);
    cout<<"Second LinkedList: ";
    display(second);
    cout<<endl;
    cout<<"Merged LinkedList: ";
    mergeLL(first,second);
    display(first);
    return 0;
}

