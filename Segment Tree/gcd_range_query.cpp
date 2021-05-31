#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int st[400000];

void printst(int n)
{
    for(int i = 0 ; i < n ; i++)
        cout << st[i] << " ";
     cout << endl;
}

int buildst(int ss, int se, int si)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return st[si];
	}
	
	int mid = ss + (se - ss)/2;
	
	int l = buildst(ss, mid, 2*si + 1);
	int r = buildst(mid +1, se, 2*si + 2);
	
	st[si] = __gcd(l,r);
	return st[si];
}

int getgcd(int qs, int qe, int ss, int se, int si)
{
	if(qs > se || qe < ss) return 0;
	
	if(qs <= ss && qe >= se) return st[si];
	
	int mid = ss + (se - ss)/2;
	return __gcd(getgcd(qs,qe,ss,mid,2*si+1), getgcd(qs, qe, mid +1, se, 2*si + 2));
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    	cin >> arr[i];
    	
    int ss= 0, se = n-1, si = 0;
    
    buildst(ss, se, si);
    printst(n);
    
    cout << getgcd(1,3,0,n-1,0) << endl;
    updatest(0,n-1,1,0,10);
    cout << getgcd(1,3,0,n-1,0) << endl;
    return 0;
}