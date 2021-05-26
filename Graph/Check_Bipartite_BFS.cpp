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

bool check_bipartite_bfs(int node, vector<int> adjls[], vector<int> &colored)
{
    queue<int> q;
    q.push(node);
    colored[node] = 0;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(auto x: adjls[temp])
        {
            if(colored[x] == -1)
            {
                colored[x] = !colored[temp];
                q.push(x);
            }
            else 
            {
                if(colored[x] == colored[temp])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int n , m;
    cin >> n >> m;
    
    int adjmt[n+1][n+1];
    int u,v;
   
    // Adjacency List
    vector<int> adjls[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }
    
    print_adjls(adjls, n , m);
    
    // Checking Bipartite
    vector<int> colored(n + 1, -1);
    bool checkbp = true;
    for(int i = 1 ; i <= n; i++)
	{
	    if(colored[i] == -1)
	   {
	        if(check_bipartite_bfs(i, adjls,colored) == false)
            {
                checkbp = false;
                break;
            }
	    }
	}
    if(checkbp)
        cout << "Bipartite!";
    else
        cout << "Not Bipartite!";
    return 0;
}