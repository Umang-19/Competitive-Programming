class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        
        int st = 0 , mxlen = 1;
        
        // Odd length
        for(int i = 0 ; i < n-1 ; i++)
        {
            int l = i, r = i;
            while( l >= 0 && r < n)
            {
                if(s[l] == s[r])
                {
                    l--;
                    r++;
                }
                else 
                    break;
            }
            int len = r - l -1;
            if(len > mxlen)
            {
                mxlen = len;
                st = l + 1 ;
            }
        }
        
        // Even length 
        for(int i = 0 ; i < n-1 ; i++)
        {
            int l = i, r = i + 1;
            while( l >= 0 && r < n)
            {
                if(s[l] == s[r])
                {
                    l--;
                    r++;
                }
                else 
                    break;
            }
            int len = r - l -1;
            if(len > mxlen)
            {
                mxlen = len;
                st = l + 1 ;
            }
        }
        
        return s.substr(st,mxlen);
        
    }
};