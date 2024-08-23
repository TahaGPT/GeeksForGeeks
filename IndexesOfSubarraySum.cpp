// Given an unsorted array arr of size n that contains only non negative integers, find a sub - array(continuous elements) that has sum equal to s.You mainly need to return the left and right indexes(1 - based indexing) of that subarray.
//     In case of multiple subarrays,return the subarray indexes which come first on moving from left to right.If no such subarray exists return an array consisting of element - 1.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        int start = 0;                             // to set the start of the array
        long long sum = 0;                         // to set the final sum
        for (int end = 0; end < arr.size(); end++) // the loop will run until the end
        {
            sum += arr[end]; // adding every number to the sum

            while (sum > s && start <= end) // if the sum is greater than the actual number, the start index will move further and the number will be subtracted keeping in view start remains lower than end
            {
                sum -= arr[start++];
            }

            if (sum == s && start <= end) // if sum equals to target
            {
                return {start + 1, end + 1};
            }
        }
        return {-1}; // if we didn't find any such combination
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends