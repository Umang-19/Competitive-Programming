#include<bits/stdc++.h>
using namespace std;

int a[100000];
int bitree[100001] = {0};

int getsum(int i)
{
    i = i + 1;
    int sum = 0;
    
    while(i > 0)
    {
        sum += bitree[i];
        i = i - (i & (-i)); // Getting parent index
    }
    return sum;
}

void updatebitree(int i, int newval, int n)
{
    int diff = newval - a[i];
    a[i] = newval;
    i = i + 1;
    while(i<=n)
    {
        bitree[i] += diff;
        i = i + (i & (-i));
    }
    return;
}

void buildbitree(int n)
{
    bitree[0] = -1;

    for(int i = 0 ; i < n ; i++)
    {
        i = i + 1;
        while(i <= n)
        {
            bitree[i] += a[i];
            i = i + (i & (-i));
        }
    }
}

void printbitree(int n)
{
    for(int i = 1; i <= n ; i++)
        cout << bitree[i] << " ";
    
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    buildbitree(n);
    cout << getsum(3) << endl;
    updatebitree(1,30,n);
    cout << getsum(3) << endl;
    return 0;
}