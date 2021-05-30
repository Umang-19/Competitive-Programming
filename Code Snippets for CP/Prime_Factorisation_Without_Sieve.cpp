#include <bits/stdc++.h>
using namespace std;

void primefactorization(int n)
{
    
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " * ";
            n = n / i;
        }
    }

    if ( n > 1)
    cout << n << " ";
    return;
}

int main()
{
    int n ;
    cout << "Enter n : ";
    cin >> n;
    primefactorization(n);
    return 0;
}