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

int main()
{
    int n , m;
    cin >> n >> m;
    int u, v, w;
 
    // Adjacency List
    vector<pair<int,int>> adjls[n];
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        adjls[u].push_back({v,w});
        adjls[v].push_back({u,w});
    }
    
    print_adjls(adjls, n , m);
    
    // TC - O(N*N)
//     vector<int> key(n , INT_MAX);
//     vector<bool> mst(n, false);
//     vector<int> parent(n , -1);
    
//     key[0] = 0;

//     int count  = 0;
//     while(count != n)
//     {
//         int minkey, mini = INT_MAX;
//         for(int i = 0 ; i < n ; i++)
//         {
//             if(mst[i] == false && key[i] < mini)
//             {
//                 mini = key[i];
//                 minkey = i;
//             }
//         }
        
//         mst[minkey] = true;
//         for(auto x : adjls[minkey])
//         {
//             if(!mst[x.first])
//             {
//                 if(x.second < key[x.first])
//                 {
//                     key[x.first] = x.second;
//                     parent[x.first] = minkey;
//                 }
//             } 
//         }
//         count++;
//     }
    
//     for(auto x: parent)
//         cout << x << " ";
    
    // Efficient = Use Priority Queue to find min ele
    vector<int> key(n , INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n , -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    key[0] = 0;
    pq.push({0,0});
    int count  = 0;
    while(count != n)
    {
        int minkey = pq.top().second;
        pq.pop();
        
        mst[minkey] = true;
        for(auto x : adjls[minkey])
        {
            if(!mst[x.first])
            {
                if(x.second < key[x.first])
                {
                    key[x.first] = x.second;
                    parent[x.first] = minkey;
                    pq.push({key[x.first], x.first});
                }
            } 
        }
        count++;
    }
    
    for(auto x: parent)
        cout << x << " ";
    return 0;
}