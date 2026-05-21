/*5.2 Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given  key element. (Time Complexity = O(n log n)).*/

#include<iostream>
using namespace std;
    vector<int> func(vector<int>&arr,int target){
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        vector<int> temp;
        while(i<=j){
            int sum = arr[i]+arr[j];
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            else{
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                break;
            }
        }
        return temp;
        
    }
int main(){
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        arr.push_back(c);
    }
    int target;
    cin >> target;
    vector<int> ans = func(arr,target);
    for(int i :ans){
        cout << i << " ";
    }
    cout << endl;
}
    return 0;
}