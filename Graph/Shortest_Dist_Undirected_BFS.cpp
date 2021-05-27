#include<bits/stdc++.h>
using namespace std;

void print_adjls(vector<int> adjls[], int n , int m)
{
    for(int i = 0; i < n ; i++)
    {
        cout << i << " -> ";
        for(int j = 0 ; j < adjls[i].size(); j++)
            cout << adjls[i][j] << " ";
        cout << endl;
    }
}

void shortestdistance(int src, int V, vector<int> adj[])
{
    vector<int> dis(V, INT_MAX);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto x: adj[node])
        {
            if(1 + dis[node] < dis[x])
            {
                dis[x] = 1 + dis[node];
                q.push(x);
            }
        }
    }
    
    for(auto i:dis)
        cout << i << " ";
    
}

int main()
{
    int n , m;
    cin >> n >> m;
    int u,v;
 
    // Adjacency List
    vector<int> adjls[n];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }
    
    print_adjls(adjls, n , m);
    
    // Shotest distance of source to every other node (BFS)
    shortestdistance(0,n,adjls);
   
    return 0;
}