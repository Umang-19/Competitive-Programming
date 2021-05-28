#include<bits/stdc++.h>
using namespace std;


struct node 
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool cmp(node x, node y)
{
    return x.wt < y.wt;
}

int findpar(int n, vector<int> &parent)
{
    if(parent[n] == n)
        return n;
    return parent[n] = findpar(parent[n], parent);
}

void myunion(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int up = findpar(u,parent);
    int vp = findpar(v, parent);
    
    if(rank[up] < rank[vp])
    {
        parent[up] = vp;
    }
    else if(rank[vp] < rank[up])
        parent[vp] = up;
    else 
    {
        parent[up] = vp;
        rank[vp]++;
    }
}

int main()
{
    int n , m;
    cin >> n >> m;
    vector<node> edges;
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(node(a,b,c));
    }
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    for(int i = 0 ; i < n ; i++)
        parent[i]= i;

    vector<int> rank(n,0);

    int cost = 0;
    vector<pair<int,int>> mst;
    for(auto i: edges)
    {
        if(findpar(i.u, parent) != findpar(i.v, parent))
        {
            cost += i.wt;
            mst.push_back({i.u,i.v});
            myunion(i.u, i.v, parent,rank);
        }
    }

    cout << cost << endl;
    for(auto i: mst)
        cout << i.first << " --- " << i.second << endl;
    
}