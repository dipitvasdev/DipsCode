// kth Smallest element(0-indexed): Quick Select 
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

int quickselect(vector<int> &arr, int start, int end, int k){
    // Assuming k<n 
    int p = partition(arr,start,end) ; 
    if(k == p){
        return arr[p] ; 
    }else if(k>p){
        return quickselect(arr,p+1,end,k) ; 
    }else{
        return quickselect(arr,start,p-1,k) ; 
    }
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
    int k  ; 
    cout<<"Enter k:" ; 
    cin>> k ; 
    cout<<quickselect(arr, 0 , n-1 ,k) ; 
}