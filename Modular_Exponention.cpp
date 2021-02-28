#include <iostream>
using namespace std;

// Normal Method Complexity - O(n)
// Complexity - O(logn)
int fastpower(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if ((b & 1) != 0)
            res = res * a;

        a = a * a;
        b = b >> 1;
    }
    return res;
}

/* Modulo Exponention
long long int calculatepower(long long int A, long long int B)
{
    if (B == 0)
        return 1;

    else if (B % 2 == 0)
        return calculatepower((A*A) % M, B >> 1) % M;
    else
        return (A * calculatepower((A*A) % M, B >> 1) % M );
}
*/

int main()
{
    cout << fastpower(2, 10);
    return 0;
}