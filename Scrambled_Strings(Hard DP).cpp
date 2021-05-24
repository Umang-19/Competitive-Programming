unordered_map<string,bool> mp;

bool solve(string a, string b)
{
    if(a.compare(b) == 0) return true;
    if(a.length() <= 1) return false;
    
    int n = a.length();
    string key = a + " " + b;
    if(mp.find(key) != mp.end()) return mp[key];
    
    for(int i = 1 ; i <= n - 1; i++)
    {
        if( ( solve(a.substr(0,i),b.substr(n-i,i)) && 
              solve(a.substr(i,n-i),b.substr(0,n-i)) 
            ) ||
            ( solve(a.substr(0,i), b.substr(0,i)) && 
              solve(a.substr(i,n-i), b.substr(i,n-i))
            )
          )   
            return mp[key] = true;
    }
    return mp[key] = false;
}

class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();
        
        if(n != m) return false;
        if(n == 0 && m == 0) return true;
        if(s1.compare(s2) == 0) return true;
        
        return solve(s1,s2);
        
    }
};