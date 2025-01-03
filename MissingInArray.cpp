// https : // www.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();

        unsigned long long tSum = (unsigned long long)(n + 1) * (n + 2) / 2;

        unsigned long long sum = accumulate(arr.begin(), arr.end(), 0ULL);

        return tSum - sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--)
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends