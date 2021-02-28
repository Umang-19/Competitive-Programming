#include <bits/stdc++.h>
using namespace std;

// a^-1 (mod p) = a^(p-2) (mod p)

unsigned long long calcpow(unsigned long long a, int p, int m)
{
    if (p == 0)
        return 1;
    else if (p % 2 == 0)
        return calcpow((a * a) % m, p >> 1, m) % m;
    else
        return (a * calcpow((a * a) % m, p >> 1, m) % m);
}

unsigned long long mulinverse(unsigned long long a, int p)
{
    return calcpow(a, p - 2, p);
}

int main()
{
    unsigned long long a = 3;
    int p = 11;
    cout << "Multiplicative inverse of a mod p : " << mulinverse(a, p);
}