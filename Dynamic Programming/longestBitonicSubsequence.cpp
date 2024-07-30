//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &nums, int n) {
        vector<int> dp1(n, 1); // from left
        vector<int> dp2(n, 1); // from right
        
        for(int i = 0; i<n; i++) {
            for(int prevIdx = 0; prevIdx < i; prevIdx++) {
                // From left
                if(nums[prevIdx] < nums[i]) {
                    dp1[i] = max(dp1[i], dp1[prevIdx] + 1);
                }
                
                // From right
                if(nums[(n - 1) - prevIdx] < nums[(n - 1) - i]) {
                    dp2[(n - 1) - i] = max(dp2[(n - 1) - i], dp2[(n - 1) - prevIdx] + 1);
                }
            }
        }
        
        int maxBitonic = 0;
        for(int i = 0; i<n; i++) {
            if(dp1[i] != 1 and dp2[i] != 1)
                maxBitonic = max(maxBitonic, dp1[i] + dp2[i] - 1);
        }
        
        return maxBitonic;
    }
  
    int LongestBitonicSequence(int n, vector<int> &nums) {
        return solve(nums, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends