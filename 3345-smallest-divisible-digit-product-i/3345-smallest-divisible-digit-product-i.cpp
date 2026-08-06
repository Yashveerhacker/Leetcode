class Solution {
public:
    int product(int n)
    {
        if(n==0)
        {
            return 0;
        }
        
        int p = 1;
        while(n>0)
        {
            int ld = n%10;
            p=p*ld;
            n=n/10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; ; i++)
        {
            int ans = product(i);
            if(ans%t==0)
            {
                return i;
            }
        }
        return -1;
    }
};