#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct  Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
};
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<"\t";
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
    }
}
int sumAtK(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    return max(lHeight,rHeight)+1;
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);   
    root->right->left=new Node(6);   
    root->right->right=new Node(7);  
    cout<<"\n";
    cout<<"Inorder Sequence: ";
    inorder(root);
    cout<<endl;
    cout<<"Prerder Sequence: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Sequence: ";
    postorder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<"Sum of given level: "<<sumAtK(root,2)<<endl;
    cout<<"Height of Tree: "<<calcHeight(root)<<endl;
}