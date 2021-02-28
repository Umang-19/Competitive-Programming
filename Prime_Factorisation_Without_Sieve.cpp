#include <bits/stdc++.h>
using namespace std;

// O(sqrt(n))
// void primefactorization(int n)
// {
//     while (n % 2 == 0)
//     {
//         cout << 2 << " * ";
//         n = n / 2;
//     }

//     for (int i = 3; i * i <= n; i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             cout << i << " * ";
//             n = n / i;
//         }
//     }

//     if ( n > 1)
//     cout << n << " ";
//     return;
// }

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