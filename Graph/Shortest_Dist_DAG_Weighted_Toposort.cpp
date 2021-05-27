#include<bits/stdc++.h>
using namespace std;

void print_adjls(vector<pair<int,int>> adjls[], int n , int m)
{
    for(int i = 0; i < n ; i++)
    {
        cout << i << " -> ";
        for(int j = 0 ; j < adjls[i].size(); j++)
            cout << "(" << adjls[i][j].first << " " << adjls[i][j].second << ") ";
        cout << endl;
    }
}


void toposort_dfs(int node, vector<pair<int,int>> adj[], stack<int> &s, vector<int> &vis)
{
    vis[node] = 1;
    for(auto x : adj[node])
    {
        if(!vis[x.first])
            toposort_dfs(x.first , adj, s, vis);
    }
    s.push(node);
}

void shortestdistance(int src, int V, vector<pair<int,int>> adj[])
{
    vector<int> vis(V , 0);
    stack<int> s;
    for(int i = 0 ; i < V ; i++)
    {
        if(!vis[i])
        {
            toposort_dfs(i, adj, s, vis);
        }
    }
    
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        if(dis[node] != INT_MAX)
        {
            for(auto x:adj[node])
            {
                if(dis[node] + x.second < dis[x.first])
                {
                    dis[x.first] = dis[node] + x.second;
                }
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
    int u,v, w;
 
    // Adjacency List
    vector<pair<int,int>> adjls[n];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v >> w;
        adjls[u].push_back({v,w});
    }
    
    print_adjls(adjls, n , m);
    
    // Shotest distance of source to every other node (BFS)
    cout << "Shortest Distance : ";
    shortestdistance(0,n,adjls);
   
    return 0;
}