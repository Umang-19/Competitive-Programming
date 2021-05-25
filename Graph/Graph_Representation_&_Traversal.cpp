#include<bits/stdc++.h>
using namespace std;

void print_bfs(vector<int> adjlist[], int n)
{
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for(auto x : adjlist[node])
        {
            if(vis[x] == false)
            {
                q.push(x);
                vis[x]= true;
            }
        }
    }
    return ;
}

bool vis[8];
    
void dfs_preorder(vector<int> adjlist[], int n, int node)
{
    cout << node << " ";
    vis[node] = true;
    
    for(auto x : adjlist[node])
    {
        if(vis[x] == false)
            dfs_preorder(adjlist,n,x);
    }
    return;
}

void dfs_postorder(vector<int> adjlist[], int n, int node)
{
     vis[node] = true;
    for(auto x : adjlist[node])
    {
        if(vis[x] == false)
            dfs_postorder(adjlist,n,x);
    }
    cout << node << " ";
   
    return;
}


int main()
{
    int n, m; // n = no. of nodes ; m = no. of edges
    cin >> n >> m;
    
    // Adjacency Matrix Representation
//     vector<vector<int>> v(n + 1 , vector<int>(n + 1,0));
//     int x , y;
//     while(m--)
//     {
//         cin >> x >> y;
//         v[x][y] = 1;
//         v[y][x] = 1;
//     }
    
//     for(int i = 1 ; i <= n ; i++)
//     {
//         for(int j = 1 ; j <= n ; j++)
//             cout << v[i][j] << " ";
//         cout << endl;
//     }
    
    // Adjacency List Representation
    vector<int> v[n + 1];
    int x , y;
    while(m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    // for(int i = 1 ; i <= n ; i++)
    // {
    //     cout << i << " -> ";
    //     for(auto x : v[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    
    // print_bfs(v,n);
    memset(vis,false,sizeof(vis));
    // cout << "Preorder : ";
    // dfs_preorder(v,n,1);

    cout << "Post-order : ";
    dfs_postorder(v,n,1);
    return 0;
}