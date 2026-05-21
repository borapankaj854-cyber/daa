/* 2.1 Given a sorted array of positive integers containing few duplicate
elements, design an algorithm and implement it using a program to find
whether the given key element is present in the array or not. If present,
then also find the number of copies of given key. (Time Complexity =
O(log n)) */

#include<iostream>
#include<vector>
using namespace std;
int first_occurence(vector<int>&arr,int target){
    int s = 0;
    int e = arr.size();
    int pos=-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==target){
            pos=mid;
            e=mid-1;
        }
        if(arr[mid]>target){
            e=mid-1;
        }
        if(arr[mid]<target){
            s=mid+1;
        }
    }
    return pos;
}

int last_occurence(vector<int>&arr,int target){
    int s = 0;
    int e = arr.size();
    int pos=-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==target){
            pos=mid;
            s=mid+1;
        }
        if(arr[mid]>target){
            e=mid-1;
        }
        if(arr[mid]<target){
            s=mid+1;
        }
    }
    return pos;
}
int main(){
    int size, key;
    int T;
    cin >> T;
    while(T!=0){
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements (sorted, duplicates allowed): ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter key to search: ";
    cin >> key;
    int first = first_occurence(arr, key);
    int last = last_occurence(arr, key);
    if(first == -1){
        cout << "Key not present in the array." << endl;
    }
    else{
        cout << "Key found in the array." << endl;
        cout << "Number of copies of key = " << last - first + 1 << endl;
    }
    T--;
}
    return 0;
}