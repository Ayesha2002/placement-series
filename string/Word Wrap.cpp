class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n+1; i++){
            int len = 0;
            for(int j = i; j < n+1; j++){
                len += nums[j-1];
                if(j > i) len+=1;
                if(len <= k){
                    int space = k - len;
                    int cost = (j == n)?0:(space*space);
                    dp[j] = min(dp[j], dp[i-1] + cost);
                }
                else break;
            }
        }
        return dp[n];
    } 
};
