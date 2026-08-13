class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = nums[0];

        for(int i = 0; i < n; i++)
        {
            sum = max(nums[i], sum+nums[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};