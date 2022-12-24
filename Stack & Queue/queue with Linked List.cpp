#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pivotIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap (arr[pivotIndex], arr[end]);
    return pivotIndex;
}
void Quicksort(int arr[], int n)
{
    stack<pair<int, int>> s; 
    int startIdx = 0; 
    int endIdx = n - 1; 
    s.push({startIdx, endIdx});  
    while (!s.empty())
    {
        startIdx = s.top().first;
        endIdx = s.top().second;
        s.pop();
        int pivotIdx = partition(arr, startIdx, endIdx);
        if (pivotIdx - 1 > startIdx) {
            s.push({startIdx, pivotIdx - 1});
        }
        if (pivotIdx + 1 < endIdx) {
            s.push({pivotIdx + 1, endIdx});
        }
    }
}
int main()
{   
    int n; 
    cin>>n;
    int arr[n]; 
    cout<<"Enter the elements of the array to be sorted:"<<endl;
    for(int i=0;i < n;i++){
        cin>>arr[i];
    }
    Quicksort(arr, n);
    cout<<"Sorted array:"<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}