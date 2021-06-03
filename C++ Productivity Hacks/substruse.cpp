#include <bits/stdc++.h>
using namespace std;
int main() 
{    
    string a = "I AM A PEACEFUL SOUL";
    int n = a.length();
    int start = -1,len;
    vector<string> words;
    for(int i = 0 ; i < n ; i++)
    {
        // cout << "start  = " << start << endl;
        if(a[i]==' ')
        {
            len = i - (start + 1);
            // cout << "start + 1 = "<< start + 1 << "    " << " len = " << len << endl;
            words.push_back(a.substr(start+1,len));
            start = i;
        }   
    }
    len = n - (start + 1);
    // cout << "start + 1 = "<< start + 1 << "    " << " len = " << len << endl;
    words.push_back(a.substr(start+1,len));

    for(auto w:words)
        cout << w << endl;
    return 0;
}
