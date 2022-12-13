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
void insertAtAnyPosition(node* &head,int val, int pos){ 
    node* n= new node(val); 
    if(head==NULL){
        cout<<"not possible";
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

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* head, int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

bool Search(node* head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }    
}

node* reverse(node* &head){
    node* prevPtr=NULL;
    node* currentPtr=head;
    node* nextPtr;
    while(currentPtr!=NULL){
        nextPtr=currentPtr->next;
        currentPtr->next=prevPtr;

        prevPtr=currentPtr;
        currentPtr=nextPtr;
    }
    return prevPtr;
}

node* sortingLL(node* &head){
    node* i;
    node* j;
    i=head;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                int temp;
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

// void splitAFunc(node *head, int position){
//     node *temp = head;
//     int i = 0;
//     while (i < 2){
//         i = i + 1;
//         temp = temp->next;
//         cout << i << " ";
//     }
//     if (temp == NULL && temp->next == NULL){
//         cout << "split impossible";
//         return;
//     }
//     int head1 = head;
//     int head2 = temp->next;
//     temp->next == NULL;
// }


int main(){
    node *head=NULL;
    insertAtTail(head,4);
    insertAtTail(head,3);
    insertAtTail(head,6);
    insertAtTail(head,1);
    display(head);
    sortingLL(head);   
    display(head);
    // splitAFunc(head,2);
    return 0;
}



