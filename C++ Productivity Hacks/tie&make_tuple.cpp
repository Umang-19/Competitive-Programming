#include <bits/stdc++.h>
using namespace std;
int main() 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d;
    tie(a,b,c,d) = make_tuple(10,20,45,60);
    cout << a << " " << b << " " << c << " " << d << endl;
    tie(a,b) = make_tuple(b,a);
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
