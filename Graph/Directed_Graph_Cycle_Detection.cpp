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

bool iscycle_dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs_vis)
{
    vis[node] = 1;
    dfs_vis[node] = 1;
    
    for(auto x: adj[node])
    {
        if(!vis[x])
        {
            if(iscycle_dfs(x,adj,vis,dfs_vis))
                return true;
        }
        else 
        {
            if(dfs_vis[x] == 1)
                return true;
        }
    }
    
    dfs_vis[node] = 0;
    return false;
}

// Kahn's Algorithm Detect Cycle BFS
bool iscycle_bfs(int V, vector<int> adj[]) 
{
	    vector<int> indeg(V,0);
	    for(int i = 0 ; i < V; i++)
	    {
	        for(auto x : adj[i])
	            indeg[x]++;
	    }
	    
	    vector<int> ans;
	    queue<int> q;
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(indeg[i] == 0)
	            q.push(i);
	    }
	    
        int cnt = 0;
	    while(!q.empty())
	    {
	        int ele = q.front();
	        ans.push_back(ele);
            cnt++;
	        q.pop();
	        
	        for(auto x : adj[ele])
	        {
	            indeg[x]--;
	            if(indeg[x] == 0)
	                q.push(x);
	        }
	    }
	    if(cnt != V) return true;
	return false;
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
    }
    
    print_adjls(adjls, n , m);
    
    // DETECT CYCLE IN DIRECTED GRAPH (DFS)
    
//     vector<int> vis(n,0);
//     vector<int> dfs_vis(n,0);
//     bool cycledetect = false;
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(!vis[i])
//         {
//             if(iscycle_dfs(i, adjls,vis, dfs_vis))
//             {
//                 cycledetect = true;
//                 break;
//             }
//         }
//     }
//     if(cycledetect)
//         cout << "Cycle is present!";
//     else
//         cout << "Cycle is not present!";
    
    
    // Cycle detection using BFS (Kahn's Algo)
     bool cycledetect = iscycle_bfs(n,adjls);
    if(cycledetect)
        cout << "Cycle is present!";
    else
        cout << "Cycle is not present!";
   
    return 0;
}