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

void sort_dfs(int node, vector<int> adj[], stack<int> &s, vector<int> &vis)
{
    vis[node] = 1;
    for(auto x : adj[node])
    {
        if(!vis[x])
            sort_dfs(x, adj,s, vis);
    }
    s.push(node);
}

vector<int> toposort_dfs(int V, vector<int> adj[])
{
    vector<int> vis(V , 0);
    stack<int> s;
    for(int i = 0 ; i < V ; i++)
    {
        if(!vis[i])
        {
            sort_dfs(i,adj,s, vis);
        }
    }
    
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Kahn's Algorithm
vector<int> toposort_bfs(int V, vector<int> adj[]) 
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
	    
	    while(!q.empty())
	    {
	        int ele = q.front();
	        ans.push_back(ele);
	        q.pop();
	        
	        for(auto x : adj[ele])
	        {
	            indeg[x]--;
	            if(indeg[x] == 0)
	                q.push(x);
	        }
	    }
	    
	return ans;
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
    
    cout << "Topological sort : ";
    vector<int> sorted = toposort_dfs(n,adjls);
    for(auto x : sorted)
        cout << x << " ";

    cout << "Topological sort : ";
    vector<int> sorted = toposort_bfs(n,adjls);
    for(auto x : sorted)
        cout << x << " ";
    return 0;
}