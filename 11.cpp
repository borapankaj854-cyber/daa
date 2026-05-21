/*  1. Given an array of nonnegative integers, design a linear algorithm
and implement it using a program to find whether given key element is
present in the array or not. Also, find total number of comparisons for
each input case. (Time Complexity = O(n), where n is the size of input).    */

#include<iostream>
#include<vector>
using namespace std;
bool linearSearch(vector<int> &arr, int n, int key, int &compare){
    // linearly finding key in array
    bool found = false;
    for(int i=0;i<n;i++){
        compare++;   //comparison counter
        if(arr[i]==key){
            found = true;
            break;
        }
    }
    return found;
}
int main(){
    int n,key,compare=0,ele;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int>arr;
    cout << "Enter elements in the array : ";
    for(int i=0;i<n;i++){
        cin >> ele;
        arr.push_back(ele);
    }
    cout << "Enter element to find in array : ";
    cin >> key;
    bool found = linearSearch(arr, n, key, compare);

    if(found==true){
        cout << "Found!!! in " << compare << " Comparisons";
    }
    else{
        cout << "Not Found!!! in " << compare << " Comparisons";
    }
    return 0;
}