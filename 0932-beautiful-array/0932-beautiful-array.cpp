class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1)
        {
            return {1};
        }
        vector<int>odd = beautifulArray((n+1)/2);
        vector<int>even = beautifulArray(n/2);
        int m = odd.size();
        int k = even.size();
        vector<int>ans;
        for(int i = 0; i < m; i++)
        {
            int x = 2*odd[i]-1;
            if(x<=n)
            {
                ans.push_back(x);
            }
        }

        for(int i = 0; i < k; i++)
        {
            int x = 2*even[i];
            if(x<=n)
            {
                ans.push_back(x);
            }
        }
     return ans;
        
    }
};