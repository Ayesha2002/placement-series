class Solution {
    int topdown(string s1, string s2, int n1, int n2) {
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        int len=0;
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int pick = 0;
                if (s1[i - 1] == s2[j - 1])
                    pick = 1 + dp[i - 1][j - 1];
                
                len=max(pick,len);

                dp[i][j] = pick;
            }
        }

        return len;
    }
    
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();
        
        return topdown(str1,str2,n1,n2);
    }
};
