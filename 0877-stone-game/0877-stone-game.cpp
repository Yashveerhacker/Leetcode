class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i];
        }
        
        for(int i = 2; i <=n; i++)
        {
            for(int j = 0; j+i-1<n ; j++)
            {
                int k = j+i-1;

                int left = piles[j] - dp[j+1][k];
                int right = piles[k] - dp[j][k-1];

                dp[j][k] = max(left,right);
            }
        }

        if(dp[0][n-1]>0)
        {
            return true;
        }
        return false;
    }
};