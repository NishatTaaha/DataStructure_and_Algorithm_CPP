#include<iostream>
using namespace std;

int binarySearch(int n,int key, int arr[]){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The values Entered: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Sorted Array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    int key;
    cout<<"\nEnter the value to be searched: ";
    cin>>key;
    
    cout<<"\nThe index of the value is: ";
    cout<<binarySearch(n,key,arr);
    return 0;
}


