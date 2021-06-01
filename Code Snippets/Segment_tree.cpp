#include <bits/stdc++.h>
using namespace std;

int v[100001];
int st[400004];

void printst(int n)
{
    for(int i = 0 ; i < n ; i++)
        cout << st[i] << " ";
     cout << endl;
}

int buildst(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = v[ss];
        return st[si];
    }

    int mid = (ss + se) / 2;
    st[si] = buildst(ss, mid, 2 * si + 1) + buildst(mid + 1, se, 2 * si + 2);
    return st[si];
}

int getsum(int qs, int qe, int ss, int se, int si)
{
    if (qs > se || qe < ss)
        return 0;

    if (qs <= ss && qe >= se)
        return st[si];

    int mid = (ss + se) / 2;

    return getsum(qs, qe, ss, mid, 2 * si + 1) +
           getsum(qs, qe, mid + 1, se, 2 * si + 2);
}

void updatest(int ss, int se, int idx, int si, int diff)
{
    if (idx < ss || idx > se)
        return;

    st[si] += diff;

    if (ss < se)
    {
        int mid = (ss + se) / 2;
        updatest(ss, mid, idx, 2 * si + 1, diff);
        updatest(mid + 1, se, idx, 2 * si + 2, diff);
    }
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    
    buildst(0, n - 1, 0);

    cout << getsum(0, 2, 0, n - 1, 0) << endl;
    cout << getsum(1, 3, 0, n - 1, 0) << endl;
    cout << getsum(0, 3, 0, n - 1, 0) << endl;

    int idx, newval;
    cin >> idx >> newval;
    int diff = newval - v[idx];
    updatest(0, n - 1, idx, 0, diff);
 
    cout << "newsum = " << getsum(0, 1, 0, n - 1, 0);
    return 0;
}