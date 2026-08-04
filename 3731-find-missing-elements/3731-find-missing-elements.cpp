class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];

        unordered_set<int>st;
        
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
            if(nums[i]>maxi)
            {
                maxi = nums[i];
            }
            else if(nums[i]<mini)
            {
                mini = nums[i];
            }
        }
        vector<int>ans;

        for(int i = mini; i<=maxi; i++)
        {
            if(st.find(i)==st.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};