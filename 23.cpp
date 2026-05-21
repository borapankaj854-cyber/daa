/*Given an array of nonnegative integers, design an algorithm and a program to count the
number of pairs of integers such that their difference is equal to a given key, K.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void count_triplet(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int start = 0, count = 0;
    int end = 1;
    while (end < arr.size())
    {
        int diff = arr[end] - arr[start];
        if (diff == target)
        {
            count++;
            start++;
            end++;
        }
        else if (diff > target)
        {
            start++;
        }
        else
        {
            end++;
        }
        while (start > 0 && start < arr.size() && arr[start] == arr[start - 1])
        {
            start++;
        }
    }
    cout << count << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        count_triplet(arr, k);
    }
    return 0;
}