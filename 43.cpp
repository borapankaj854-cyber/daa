/*Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))*/

#include<iostream>
#include<vector>
using namespace std;

int find_pivot_indx(vector<int>&arr,int st,int end){
    int idx=st-1; //alwys one less then the start
    int j=0;
    int pivot=arr[end];
    for(j=st;j<end;j++){ 
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    //now put the pivot element to its correct place
    swap(arr[idx+1],arr[end]);
    return idx+1;
}

int quick_select(vector<int>&arr,int st,int end,int k)
{
    if(st <= end){

        int pivot_indx = find_pivot_indx(arr,st,end);

        if(pivot_indx == k){
            return arr[pivot_indx];
        }
            return quick_select(arr,st,pivot_indx-1,k);
            return quick_select(arr,pivot_indx+1,end,k);
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int k;
        cin >> k;
        int ans = quick_select(arr,0,n-1,k-1);
        cout << ans << endl;
    }
    return 0;
}