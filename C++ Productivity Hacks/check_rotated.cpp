#include <bits/stdc++.h>
using namespace std;
int main() 
{    
    string A = "ABCD";
    string B = "DBAC";

    if(A.length() != B.length())
        cout << "FALSE"<<endl;
    
    string temp = A + A;

    //TODO: NOICCCEEEE!!!! 
    if(temp.find(B) != string::npos)
        cout << "TRUE" << endl;
    else
    cout << "FALSE"<<endl;
    return 0;
}
