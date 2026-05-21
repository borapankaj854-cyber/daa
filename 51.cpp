/*5.1 Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)*/

#include<iostream>
using namespace std;
    int count_max_occur(vector<char>&str){
        int hash[256] ={0};
        for(int i=0;i<str.size();i++){
            hash[str[i]]++;
        }
        int max = INT_MIN;
        int code;
        for(int i=0;i<256;i++){
            if(max<hash[i]){
                max = hash[i];
                code=i;
            }
        }
        if(max==1){
            return -1;
        }
        return code;
    }
int main(){
    int t;
    cin >> t;
    while(t--){
    vector<char> str;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char ch;
        cin >> ch;
        str.push_back(ch);
    }
    char ans = count_max_occur(str);
    if(ans==-1) cout << "No duplicates" << endl;
    else cout << ans;
    }
    return 0;
}