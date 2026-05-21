/*Given an unsorted array of integers, design an algorithm and implement a program tosort this array using selection sort. Your program should also find number of comparisons and number of swaps required.*/

#include<iostream>
using namespace std;
void selection_sort(vector<int>&nums,int &swaps,int &comp){
    for(int i=0;i<nums.size();i++){
        int min=nums[i];
        int index=i;
        int j=i+1;
        while(j<nums.size()){
            if(nums[j]<min){
                comp++;
                min=nums[j];
                index=j;
            }
            j++;
        }
        swap(nums[i],nums[index]);
        swaps++;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        int swaps = 0, comp = 0;
        for(int x : nums){
            cout << x << " ";
        }
        cout << endl;
        selection_sort(nums, swaps, comp);
        for(int x : nums){
            cout << x << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comp << endl;
        cout << "Swaps: " << swaps << endl;
    }
    return 0;
}