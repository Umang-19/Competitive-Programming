#include <bits/stdc++.h>
using namespace std;

void printst(vector<int> st)
{
    for(auto x : st)
        cout << x << " ";
     cout << endl;
}

int buildst(int l, int r, int i, vector<int> &st, vector<int> v)
{
    if (l == r)
    {
        st[i] = v[l];
        return st[i];
    }

    int mid = (l + r) / 2;
    st[i] = buildst(l, mid, 2 * i + 1, st, v) + buildst(mid + 1, r, 2 * i + 2, st, v);
    return st[i];
}

int getsum(int qs, int qe, int ss, int se, int i, vector<int> st)
{
    if (qs > se || qe < ss)
        return 0;

    if (qs <= ss && qe >= se)
        return st[i];

    int mid = (ss + se) / 2;

    return getsum(qs, qe, ss, mid, 2 * i + 1, st) +
           getsum(qs, qe, mid + 1, se, 2 * i + 2, st);
}

void updatest(int ss, int se, int idx, int si, int diff, vector<int>& st)
{
    if (idx < ss || idx > se)
        return;

    st[si] += diff;

    if (ss < se)
    {
        int mid = (ss + se) / 2;
        updatest(ss, mid, idx, 2 * si + 1, diff, st);
        updatest(mid + 1, se, idx, 2 * si + 2, diff, st);
    }
}

int main()
{
    vector<int> v;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    int size = 2 * pow(2, ceil(log(n))) - 1;
    vector<int> st(size, -1);
    int rootval = buildst(0, n - 1, 0, st, v);

    cout << getsum(0, 2, 0, n - 1, 0, st) << endl;
    cout << getsum(1, 3, 0, n - 1, 0, st) << endl;
    cout << getsum(0, 3, 0, n - 1, 0, st) << endl;

    int idx, newval;
    cin >> idx >> newval;
    int diff = newval - v[idx];
    updatest(0, n - 1, idx, 0, diff, st);
 
    cout << "newsum = " << getsum(0, 1, 0, n - 1, 0, st);
    return 0;
}