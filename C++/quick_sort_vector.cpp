#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end] ; 
    int i = start - 1 ; 
    int j = start ; 
    // Seperating elements less than and greater than the pivot
    for(int j = start ; j < end ; j++){
        if(arr[j] < pivot){
            i++ ; 
            swap(arr[i], arr[j]) ; 
        }
    }
    // Bringing the pivot element to correct position
    swap(arr[i+1],arr[end]) ; 
    return i + 1 ; 
}
void quicksort(vector<int> &arr, int start, int end){
    // Base Case
    if(start >= end){
        return ; 
    }
    // Recursive Case
    int pivot = partition(arr,start, end) ; 
    quicksort(arr, start, pivot -1 ) ; 
    quicksort(arr, pivot+1, end) ; 
}
int main(){
    vector<int> arr ; 
    int n  ;
    cout<<"Enter number of elements:" ; 
    cin>>n ; 
    cout<<"Enter array of elements:" ; 
    for(int i = 0 ; i < n ; i++){
        int num ; 
        cin>>num ; 
        arr.push_back(num) ; 
    }
    quicksort(arr,0,n-1) ; 
     cout<<"Sorted:"<<endl ; 
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout<<*it<<" "; 
    }
}