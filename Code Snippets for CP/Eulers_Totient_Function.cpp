#include <iostream>
using namespace std;

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
    cout << "Value of phi(n) : " << phin(n) << endl;
}
