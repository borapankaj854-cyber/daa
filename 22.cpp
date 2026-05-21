/* Given a sorted array of positive integers, design an algorithm
and implement it using a program to find three indices i, j, k such that
arr[i] + arr[j] = arr[k]. */

#include<iostream>
#include<vector>
using namespace std;

bool threeIndices(vector<int> arr){
    int n = arr.size();
    for(int end = n-1; end >= 2; end--){
        int start = 0;
        int nxt = end-1;

        while(start < nxt){
            int sum = arr[start] + arr[nxt];

            if(sum == arr[end]){
                cout << start << "," << nxt << "," << end << endl;
                return true;
            }
            else if(sum < arr[end]){
                start++;
            }
            else{
                nxt--;
            }
        }
    }
    return false;
}
int main(){
    int T;
    cin >> T;
    while(T!=0){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(!threeIndices(arr)){
            cout << "No sequence found." << endl;
        }
        T--;
    }

    return 0;
}