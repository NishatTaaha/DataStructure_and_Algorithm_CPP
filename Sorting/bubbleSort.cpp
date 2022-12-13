#include<iostream>
using namespace std;
void bubbleSort(int a[],int n){
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main (){
    int n,a[100];
    cout<<"Enter the number of element: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    bubbleSort(a,n);
    cout<<"Sorted list: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}
