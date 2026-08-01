class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }

        for(int i = 2; i<=n; i++)
        {
            for(int j = 0; j+i-1<n; j++)
            {
                int k = j+i-1;
                int left = nums[j] - dp[j+1][k];
                int right = nums[k] - dp[j][k-1];

                dp[j][k] = max(left,right);
            }
        }
        if(dp[0][n-1]>=0)
        {
            return true;
        }
        return false;
    }
};