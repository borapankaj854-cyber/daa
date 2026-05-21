/*Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shift i.e shifts total number of times the array elements are shifted from their place required for sorting the array.*/

#include<iostream>
using namespace std;
void insertion_sort(vector<int>&nums,int &comp,int &shift){
    for(int i=1;i<nums.size();i++){
        int j=i-1;
        int store=nums[i];
        while(j>=0 && nums[j]>=store){
            comp++;
            nums[j+1]=nums[j];
            j--;
            shift++;
        }
        nums[j+1]=store;
        shift++;

    }
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int comp = 0, shift = 0;
    insertion_sort(nums, comp, shift);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;
    cout << "Comparisons: " << comp << endl;
    cout << "Shifts: " << shift << endl;
    return 0;
}