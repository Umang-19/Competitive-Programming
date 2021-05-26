// DFS Traversal
// BFS Traversal
// Detect Cycle in Undirected (DFS & BFS)

#include<bits/stdc++.h>
using namespace std;

void print_adjls(vector<int> adjls[], int n , int m)
{
    for(int i = 1; i <=n ; i++)
    {
        cout << i << " -> ";
        for(int j = 0 ; j < adjls[i].size(); j++)
            cout << adjls[i][j] << " ";
        cout << endl;
    }
}

void dfs(int node, vector<int> adjls[], vector<bool> &vis, vector<int> &dfsans)
{
    dfsans.push_back(node);
    vis[node] = true;
    if(adjls[node].size() == 0)
        return;
    
    for(auto x: adjls[node])
    {
        if(!vis[x])
        {
            dfs(x, adjls, vis, dfsans);
        }
    }
}

bool iscycle_dfs(int node,  vector<int> adjls[], vector<bool> &vis, int parent)
{
    vis[node] = true;
    if(adjls[node].size() == 0)
        return false;
    for(auto x: adjls[node])
    {
        if(!vis[x])
        {
            if(iscycle_dfs(x, adjls, vis, node)) 
                return true;
        }
        else if(x != parent)
            return true;
    }
    return false;
}

bool iscycle_bfs(int node,  vector<int> adjls[], vector<bool> &vis, int parent)
{
    queue<pair<int,int>> q;
    q.push({node,parent});
    vis[node] = true;
    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        for(auto x : adjls[temp.first])
        {
            if(!vis[x])
            {
                q.push({x,temp.first});
                vis[x] = true;
            }
            else if(x != temp.second)
                return true;
        }
    }
    return false;
}

int main()
{
    int n , m;
    cin >> n >> m;
    
    int adjmt[n+1][n+1];
    int u,v;
    
    // Adjacency Matrix
    // for(int i = 0 ; i < m ; i++)
    // {
    //     cin >> u >> v;
    //     adjmt[u][v] = 1;
    //     adjmt[v][u] = 1;
    // }
    
    // Adjacency List
    vector<int> adjls[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }
    
    print_adjls(adjls, n , m);
    
    // Breadth First Search Traversal
    int ncomponents = 0;
    vector<bool> vis(n + 1, false);
// 	queue<int> q;
// 	cout << "Breadth First Search : ";
//     for(int i = 1 ; i <= n ; i++)
//     {
//         if(!vis[i])
//         {   
//             ncomponents++;
// 	        q.push(i);
// 	        vis[i] = true;
	            
// 	        while(!q.empty())
// 	        {
// 	            int x = q.front();
// 	            cout << x << " ";
// 	            q.pop();
// 	            for(auto ele : adjls[x])
// 	            {
// 	                if(!vis[ele])
// 	                {
// 	                    q.push(ele);
// 	                    vis[ele] = true;
// 	                }
// 	            }
// 	        }
//         }
//     }
//     cout << "\nTotal components = " << ncomponents << endl;
    
    // Depth First Search Traversal
    // cout << "Depth First Search : ";
    // vector<int> dfsans;
    // for(int i = 1 ; i <= n ; i++)
    // {
    //     if(!vis[i])
    //     {
    //         dfs(i, adjls, vis, dfsans);
    //     }
    // }
    // for(auto temp: dfsans)
    //     cout << temp << " ";
    
    // Cycle Detection using DFS
    bool cycledetect = false;
    // for(int i = 1 ; i <= n ; i++)
    // {
    //     if(!vis[i])
    //     {
    //         if(iscycle_dfs(i, adjls,vis, -1))
    //         {
    //             cycledetect = true;
    //             break;
    //         }
    //     }
    // }
    
    // Cycle Detection Using BFS
    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            if(iscycle_bfs(i, adjls,vis, -1))
            {
                cycledetect = true;
                break;
            }
        }
    }
    if(cycledetect)
        cout << "Cycle is present!";
    else
        cout << "Cycle is not present!";
    return 0;
}