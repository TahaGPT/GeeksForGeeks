// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?page=1&difficulty=Basic,Easy&sortBy=submissions

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> num;
        num.push_back(arr[0]);
        int j = 0, n = arr.size();
        for(int i = 1; i < n; i++)
        {
            for(; j >=0 && num[j] < arr[i]; j--)
                num.pop_back();
            num.push_back(arr[i]);
            j++;
        }
        return num;
    }
};