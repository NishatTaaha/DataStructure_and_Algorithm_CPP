#include<iostream>
using namespace std;
#define n 20
class queue{
    int *arr;
    int front;
    int rear;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        rear=-1;
    }
    void push(int x){
        if(rear==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear++;
        arr[rear]=x;
        if(front==-1){
            front++;
        }
    }
    void pop(){
        if(front==-1 || front>rear){
            cout<<"No Element in queue!";
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>rear){
            cout<<"No Element In Queue!"<<endl;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1 || front>rear){
            return true;
        }
        return false;
    }
    void display(){
        int i;
        if(empty()){
            cout<<endl<<"Empty queue"<<endl;
        }
        else{
            cout<<endl;
            for(i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
    
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    // q.pop();
    q.display();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.empty()<<endl;
    return 0;
}

