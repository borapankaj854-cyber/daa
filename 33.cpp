#include<iostream>
#include<vector>
using namespace std;

bool duplicate = false;

void merge(vector<int>&arr,int start,int mid,int end){
    int i = start; int j = mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i] == arr[j])
        duplicate = true;
        
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
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
        duplicate = false;
        merge_sort(arr,0,n-1);
        if(duplicate)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}