#include <bits/stdc++.h>
using namespace std;

int multiply(int a, int b, int ans)
{
    if (a & 1 != 0)
        ans = ans + b;

    if (a == 1)
        return ans;

    return multiply(a >> 1, b << 1, ans);
}

int main()
{
    cout << multiply(24, 50, 0);
    return 0;
}