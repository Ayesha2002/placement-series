class Solution {
public:

    
    int foo(int n, vector<int> &dp) {
        int prev1 = 1;
        int prev2 = 1;
        int cur=1;
        for(int i=2; i<=n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = foo(n, dp);
        return ans;
    }
};
