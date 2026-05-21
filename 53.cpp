/*You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))*/
#include<iostream>
using namespace std;
vector<int> common(vector<int>&arr, vector<int>&brr){
    int i=0;
    int j=0;
    int m=arr.size();
    int n=brr.size();
    vector<int> temp;
    while(i<m && j<n){
        if(arr[i]==brr[j]){
            temp.push_back(arr[i]);
            i++; j++;
        }
        else if(arr[i]>brr[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return temp;
}
int main(void){
    int t;
    cin >> t;
    int m,n;
    while(t--){
        vector<int> arr;
        vector<int> brr;
        cin >> m;
        cin >> n;
        for(int i=0;i<m;i++){
            int c;
            cin >> c;
            arr.push_back(c);
        }
        for(int i=0;i<n;i++){
            int c;
            cin >> c;
            brr.push_back(c);
        }
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        vector<int> ans = common(arr,brr);
        for(int i:ans){
            cout << i << " ";
        }
         
    }
    return 0;
}