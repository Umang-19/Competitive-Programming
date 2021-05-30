#include <bits/stdc++.h>
using namespace std;

#define max 1001

int spf[max];

void sieve()
{
    for (int i = 0; i < max; i++)
        spf[i] = i;

    for (int i = 2; i * i < max; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < max; j = j + i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void primefactorization(int n)
{
    sieve();
    while (n > 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    primefactorization(n);
    return 0;
}