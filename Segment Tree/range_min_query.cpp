#include<bits/stdc++.h>
using namespace std;
int st[400004];
int v[100001];

int buildst(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = v[ss];
        return st[si];
    }

    int mid = ss + (se - ss) / 2;
    st[si] = min(buildst(ss, mid, 2 * si + 1) , buildst(mid + 1, se, 2 * si + 2));
    return st[si];
}


int getmin(int qs, int qe, int ss, int se, int si)
{
	if(qs > se || qe < ss) return INT_MAX;
	
	if(qs <= ss && qe >= se) return st[si];
	
	int mid = ss + (se - ss)/2;
	return min(getmin(qs, qe, ss, mid, 2 * si + 1), getmin(qs, qe, mid + 1, se, 2 * si + 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n, x;
    cin >> n;
 
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
    buildst(0, n - 1, 0);
    
    int q, qs, qe;
    cin >> q;
    while(q--)
    {
    	cin >> qs >> qe;
    	cout << getmin(qs, qe, 0, n-1, 0) << endl;
    }
    
    return 0;
}