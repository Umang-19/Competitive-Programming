#include <iostream>
using namespace std;

// // TC : O(nlogn)
// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }
// void phin1(int n)
// {
//     int ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (gcd(i, n) == 1)
//             ans++;
//     }
//     return ans;
// }

// TC : O(sqrt(n))
// int phin2(int n)
// {
//     int ans = n;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n = n / i;
//             ans = ans - (ans / i);
//         }
//     }
//     if (n > 1)
//         ans = ans - (ans / n);
//     return ans;
// }

// TC : O(nloglogn)
int phin(int n)
{
    int phi[n + 1];
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j = j + i)
                phi[j] = phi[j] - (phi[j] / i);
        }
    }
    return phi[n];
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    // cout << "Value of phi(n) : " << phin1(n) << endl;
    // cout << "Value of phi(n) : " << phin2(n) << endl;
    cout << "Value of phi(n) : " << phin(n) << endl;
}
