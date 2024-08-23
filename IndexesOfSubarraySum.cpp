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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class Solution                                                                                           ////////////////////////////////////////////////////////
// {                                                                                                        ////////////////////////////////////////////////////////
// public:                                                                                                  ////////////////////////////////////////////////////////
//     // Function to find a continuous sub-array which adds up to a given number.                          ////////////////////////////////////////////////////////
//     vector<int> subarraySum(vector<int> arr, int n, long long s)                                         ////////////////////////////////////////////////////////
//     {                                                                                                    ////////////////////////////////////////////////////////
//         if (n == 1 && arr[0] == s) // if the size is only 1, than the same index will be returned        ////////////////////////////////////////////////////////
//         {                                                                                                ////////////////////////////////////////////////////////
//             return {1, 1};                                                                               ////////////////////////////////////////////////////////
//         }                                                                                                ////////////////////////////////////////////////////////
//         if (s == 0) // if target is zero                                                                 ////////////////////////////////////////////////////////
//         {                                                                                                ////////////////////////////////////////////////////////
//             for (int i = 0; i < arr.size(); i++) // then it'll look for zero                             ////////////////////////////////////////////////////////
//             {                                                                                            ////////////////////////////////////////////////////////
//                 if (s == arr[i])                                                                         ////////////////////////////////////////////////////////
//                 {                                                                                        ////////////////////////////////////////////////////////
//                     return {i + 1, i + 1};                                                               ////////////////////////////////////////////////////////
//                 }                                                                                        ////////////////////////////////////////////////////////
//             }                                                                                            ////////////////////////////////////////////////////////
//         }                                                                                                ////////////////////////////////////////////////////////
//         for (int i = 0; i < arr.size() - 1; i++) // fouter loop for resetting sum                        ////////////////////////////////////////////////////////
//         {                                                                                                ////////////////////////////////////////////////////////
// int sum = arr[i];                                                                                        ////////////////////////////////////////////////////////
// for (int j = i + 1; j <= arr.size(); j++) // inner loop to update sum                                    ////////////////////////////////////////////////////////
// {                                                                                                        ////////////////////////////////////////////////////////
//     if (sum < s && j < arr.size()) // if sum has not reached target                                      ////////////////////////////////////////////////////////
//         sum += arr[j];                                                                                   ////////////////////////////////////////////////////////
//     else if (sum == s) // if sum has achieved the target                                                 ////////////////////////////////////////////////////////
//         return {i + 1, j};                                                                               ////////////////////////////////////////////////////////
//     else // if sum exceeded the target                                                                   ////////////////////////////////////////////////////////
//         break;                                                                                           ////////////////////////////////////////////////////////
// }                                                                                                        ////////////////////////////////////////////////////////
// }                                                                                                        ////////////////////////////////////////////////////////
// return {-1};                                                                                             ////////////////////////////////////////////////////////
// }                                                                                                        ////////////////////////////////////////////////////////
// };                                                                                                       ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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