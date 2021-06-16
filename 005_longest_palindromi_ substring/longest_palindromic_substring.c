class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max = 0;
        int max_idx = -1;
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n ; i++){
            dp[i][i] = 1;
            if(s[i] == s[i+1])
                dp[i][i+1] = 1;
        }
        for(int i = n-3; i >= 0 ; i--)
        {
            for(int j = n-1; j > i; j--)
            {
                if(dp[i+1][j-1] != 1)
                    continue;
                if(s[i] == s[j]){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = n-1; j >= i ; j--)
            {
                if(dp[i][j] == 1 && (max < (j-i+1))){
                    max = (j-i+1);
                    max_idx = i;
                }
                
            }
        }
        return s.substr(max_idx, max);
    }
};