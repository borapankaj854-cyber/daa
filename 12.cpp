/*.  Given an already sorted array of positive integers, design an
algorithm and implement it using a program to find whether given key
element is present in the array or not. Also, find total number of
comparisons for each input case. (Time Complexity = O(nlogn), where
n is the size of input).                                       */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool binarySearch(vector<int> &arr, int n, int key, int &compare){
    int start = 0;
    int end = n-1;
    bool found = false;
    while(start <= end){
        compare++;
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
            found = true;
            break;
        }
        compare++;
        if(arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return found;
}
int main(){
    int n,key,compare=0,ele;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr;
    cout << "Enter elements in the array : ";
    for(int i=0;i<n;i++){
        cin >> ele;
        arr.push_back(ele);
    }

    sort(arr.begin(),arr.end());

    cout << "Sorted Array : ";
    for(int i:arr) cout << i << " ";
    cout << endl;

    cout << "Enter element to find in array : ";
    cin >> key;
    bool found = binarySearch(arr, n, key, compare);

    if(found == true){
        cout << "Found in " << compare << " comparisons";
    }
    else{
        cout << "Not Found in " << compare << " comparisons";
    }
    return 0;
}