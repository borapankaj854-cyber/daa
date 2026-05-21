/*Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these
subarrays after sorting each one of them. Your program should also find number of
comparisons and inversions during sorting the array. */

#include<iostream>
#include<vector>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void merge(vector<int>&arr,int start,int mid,int end){
    int i = start; int j = mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        comparisons++;
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            inversions += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){ //leftover sorted subarray push directly into temp
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[start+i]=temp[i];
    }
}

void merge_sort(vector<int>&arr,int start,int end){
    //base condition->
    if(start>=end) return;
    int mid = start + (end-start)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
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
        comparisons = 0;
        inversions = 0;
        merge_sort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "inversions = " << inversions << endl;
    }

    return 0;
}