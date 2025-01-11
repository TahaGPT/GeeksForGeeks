// https : // www.geeksforgeeks.org/problems/second-largest3735/1?page=1&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>

        using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        // Code Here
        int largest = -1, sLargest = -1, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > largest)
            {
                sLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > sLargest && arr[i] < largest)
                sLargest = arr[i];
        }
        return sLargest;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends