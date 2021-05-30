#include<bits/stdc++.h>
using namespace std;

int buildst(int ss, int se, int si, vector<int> &st, vector<int> v)
{
    if (ss == se)
    {
        st[si] = v[ss];
        return st[si];
    }

    int mid = ss + (se - ss) / 2;
    st[si] = min(buildst(ss, mid, 2 * si + 1, st, v) , buildst(mid + 1, se, 2 * si + 2, st, v));
    return st[si];
}


int getmin(int qs, int qe, int ss, int se, int si, vector<int> st)
{
	if(qs > se || qe < ss) return INT_MAX;
	
	if(qs <= ss && qe >= se) return st[si];
	
	int mid = ss + (se - ss)/2;
	return min(getmin(qs, qe, ss, mid, 2 * si + 1, st), getmin(qs, qe, mid + 1, se, 2 * si + 2, st));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    
    // int size = 2 * pow(2, ceil(log2(n))) - 1;
    vector<int> st(4*n);
    int rootval = buildst(0, n - 1, 0, st, v);
    
    int q, qs, qe;
    cin >> q;
    while(q--)
    {
    	cin >> qs >> qe;
    	cout << getmin(qs, qe, 0, n-1, 0, st) << endl;
    }
    
    return 0;
}