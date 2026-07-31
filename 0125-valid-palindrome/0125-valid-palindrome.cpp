class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9')
            {
                if(s[i]>='A' && s[i]<='Z')
                {
                    str+=char(s[i]+32);
                }
                else
                {
                    str+=s[i];
                }
            }
        }
        string rev = str;
        int i = 0;
        int j = str.size()-1;
        while(j>i)
        {
            char temp = rev[i];
            rev[i] = rev[j];
            rev[j] = temp;
            i++;
            j--;
        }
        if(str == rev)
        {
            return true;
        }
        return false;
    }
};