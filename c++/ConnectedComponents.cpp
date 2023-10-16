//username : pratikkumar399
// aim : find connected components in graph
// date : 17/10/23

#include<bits/stdc++.h> 
using namespace std ;

void dfs(int node ,vector<int> &vis ,  vector<int> graph[] ,
    vector<int> &components ){
	vis[node]=1;
	components.push_back(node) ;
	for(auto it : graph[node]){
		if(!vis[it]){
            dfs(it, vis , graph, components) ;
        }

	}

}

int main(){
	int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> visited(n , 0) ;
    
    int count = 0 ;
    vector<int> components ;
    for(int i = 0 ; i < n ; i++){
      if(!visited[i] ){
            count++ ;
            components.clear() ;
            dfs(i , visited , adj , components) ;
            for(auto it : components){
                cout<<it<<" " ;
            }
            cout<<endl ;
        }
    }
    cout<<count<<endl ;
	return 0 ;
}	
