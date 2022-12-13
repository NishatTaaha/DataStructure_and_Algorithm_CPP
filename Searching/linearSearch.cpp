#include<iostream>
using namespace std;

int linearSearch(int n, int key,int arr[]){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the avlues of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The values Entered: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int key;
    cout<<"\nEnter the value to be searched: ";
    cin>>key;
    
    cout<<"\nThe index of the value is: ";
    cout<<linearSearch(n,key,arr);
    return 0;
}

