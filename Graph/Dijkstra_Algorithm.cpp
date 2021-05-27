// Shortest Dist in Undirected Weighted Graph
#include<bits/stdc++.h>
using namespace std;

void print_adjls(vector<pair<int,int>> adjls[], int n , int m)
{
    for(int i = 1; i <= n ; i++)
    {
        cout << i << " -> ";
        for(int j = 0 ; j < adjls[i].size(); j++)
            cout << "(" << adjls[i][j].first << " " << adjls[i][j].second << ") ";
        cout << endl;
    }
}

vector<int> shortestdistance(int src, int n , vector<pair<int,int>> adj[])
{
    vector<int> dis(n + 1, INT_MAX);
    dis[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,src});
    
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        for(auto x: adj[node.second])
        {
            if(node.first + x.second < dis[x.first])
            {
                dis[x.first] = node.first + x.second;
                pq.push({dis[x.first], x.first});
            }
        }
    }
    return dis;
}
int main()
{
    int n , m;
    cin >> n >> m;
    int u, v, w;
 
    // Adjacency List
    vector<pair<int,int>> adjls[n + 1];
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        adjls[u].push_back({v,w});
        adjls[v].push_back({u,w});
    }
    
    print_adjls(adjls, n , m);
    
    // Shortest distance of source to every other node (BFS)
    cout << "Shortest Distance : ";
    vector<int> ans = shortestdistance(1, n, adjls);
    for(int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
   
    return 0;
}