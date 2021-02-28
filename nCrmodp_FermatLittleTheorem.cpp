#include <bits/stdc++.h>
using namespace std;

unsigned long long calcpow(unsigned long long int n, unsigned long long int p, unsigned long long int m)
{
    if (p == 0)
        return 1;

    else if (p % 2 == 0)
        return calcpow((n * n) % m, p >> 1, m) % m;

    else
        return (n * calcpow((n * n) % m, p >> 1, m)) % m;
}

unsigned long long modinv(unsigned long long n, unsigned long long p)
{
    return calcpow(n, p - 2, p);
}

unsigned long long nCrmodp(unsigned long long n, unsigned long long r, unsigned long long p)
{

    unsigned long long fact[n + 1];

    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }

    return ((fact[n] % p) * (modinv(fact[n - r], p) % p) * (modinv(fact[r], p) % p)) % p;
}

int main()
{
    unsigned long long n, r, p;
    n = 10;
    r = 2;
    p = 13;
    cout << " nCr mod p : " << nCrmodp(n, r, p);
    return 0;
}