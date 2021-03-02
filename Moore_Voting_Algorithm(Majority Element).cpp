#include <bits/stdc++.h>
using namespace std;

int majority_element(int a[], int n)
{
    if (n == 1)
        return a[0];

    int ansidx = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[ansidx])
            count++;
        else
            count--;

        if (count == 0)
        {
            ansidx = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[ansidx])
            count++;
    }

    if (count > (n / 2))
        return a[ansidx];
    else
        return -1;
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << majority_element(a, size) << endl;
    return 0;
}