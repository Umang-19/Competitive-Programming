vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int n = V;
	    vector<int> indeg(n,0);
	    
	   // int E = adj.size(); // Giving error
	   int E = V // E should be no. of edges
	    for(int i = 0 ; i < E; i++)
	    {
	        for(int j = 0 ; j < adj[i].size(); j++)
	            indeg[adj[i][j]]++;
	    }
	    
	    vector<int> ans;
	    queue<int> q;
	    for(int i = 0 ; i < n ; i++)
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
};