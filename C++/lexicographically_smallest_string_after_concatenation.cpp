// IN BUILT SORT VERSION - LEXIOGRAPHICALLY SMALLEST STRING AFTER CONCATENATION
#include <bits/stdc++.h>
using namespace std; 
// Make comparator function 
bool compareString(const string a, const string b){
    return a + b < b + a ; 
}
int main(){
    vector<string> arr ; 
    int n ; 
    cout<<"Enter number of strings:" ; 
    cin>>n ; 
    cout<<"Enter array of strings:" ; 
    for(int i = 0 ; i < n ; i++){
        string s ; 
        cin>>s ; 
        arr.push_back(s) ; 
    }
    // arrange in right order 
    sort(arr.begin(), arr.end(), compareString) ;
     // Concatenate to give output 
    string concatenated  = "" ; 
    for(auto it = arr.begin(); it != arr.end(); it++){
        concatenated += *it ; 
    }
    cout<<"Smallest String after concatenation"<<endl ; 
    cout<<concatenated ;

}