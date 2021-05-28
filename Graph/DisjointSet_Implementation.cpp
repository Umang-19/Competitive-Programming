#include<bits/stdc++.h>
using namespace std;

int parent[10000];
int rank[10000];

void makeset(int n)
{
    for(int i =  1 ; i<= n ; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findpar(int n)
{
    if(n == parent[n])
        return n;
 
        // return findpar(parent[n]); // Not path compressed
        return parent[n] = findpar(parent[n]);
}

void myunion(int u , int v)
{
    int up = findpar(u);
    int vp = findpar(v);
    
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

int main() {
    makeset(7);
    int u, v;
    int operations;
    cin >> operations;
    while(operations--)
    {
        cin >> u >> v;
        myunion(u,v);
    }
    
    // Find 2 nodes belong to same component or not
    int a , b;
    cin >> a >> b;
    if(findpar(a) != findpar(b))
        cout << "Belongs to diff components!";
    else 
        cout << "Same component! ";
    return 0;
}