/*GRAPH FUNCTIONS*/


//BFS
vector<int> bfsOfGraph(int s,int V, vector<vector<int> > &adj)
{
	queue<int> q;
	vector<bool> vis(V,false);
	q.push(s);   //source
	vis[s]=1;
	vector<int> bfs;    
	while(!q.empty()){
	    int u=q.front();
	    q.pop(); 
	    //for all v adj to u push vertex in queue and mark visited
	    for(int i=0;i<adj[u].size();i++){
	        if(vis[adj[u][i]]==false){
	            q.push(adj[u][i]);
	            vis[adj[u][i]]=1;
	        }
	    }
	    bfs.push_back(u);
	}
	return bfs;
}

//DFS
void dfsOfGraph(int u,vector<vector<int> > adj,vector<bool> vis,vector<int> &dfs){
	dfs.push_back(u);
	vis[u]=1;
	//for all v adj to u recursively call the function if not visited;
	for(int i=0;i<adj[u].size();i++){
		if(!vis[adj[u][i]]){
			dfsOfGraph(adj[u][i],adj,vis,dfs);
		}
	}
	return;
}

//Cycle detection in undirected graph  (DFS approach) using parent int 
bool cycle(int u,vector<vector<int> > &adj,vector<bool> &vis,int parent){
	vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
    	if(!vis[adj[u][i]]){
            if(cycle(adj[u][i],V,adj,vis,u)){
                return true;
            }
        }else if(adj[u][i]!=parent){
            return true;
        }
    }
    return false;
}

//Cycle detection in undirected graph  (BFS approach) using parent vector 
bool isCycle(int s,int V, vector<vector<int> > &adj)
{
	vector<bool> vis(V,false);
	queue<int> q;
	vector<int> par(V,-1);
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
	    q.pop();
	    for(int i=0;i<adj[u].size();i++){
	    	if(!vis[adj[u][j]]){
	        	q.push(adj[u][j]);
	            vis[adj[u][j]]=1;
	            par[adj[u][j]]=u;
	       	}else if(adj[u][j]!=par[u]){
	            return true;
	        }
	    }
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cycle Detection in undirected graph using disjoint set and union (used in kruskals algo to detect cycle)
// edges are given 
struct edge{
	int src,des;
	
};
//rank of parent/root > child
struct subset{
	int parent,rank;
};
//find parent/root of the subset
int find(vector<subset> &subsets,int u){
	if(subsets[u].parent!=u){
		return find(subsets,subsets[u].parent);
	}
	return subsets[u].parent;
}
void unionOf(vector<subset> &subsets, int x, int y){
	if(subsets[x].rank<subsets[y].rank){
		subsets[x].parent=y;
	}else if(subsets[x].rank>subsets[y].rank){
		subsets[y].parent=x;
	}else{
		subsets[x].parent=y;
		subsets[y].rank++;
	}
}
bool isCycleDisjoint(int V, vector<edge> &edges){
	vector<subset> subsets(V);
	for(int i=0;i<V;i++){
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	for(int i=0;i<edges.size();i++){
		int x=find(subsets,edges[i].src);
		int y=find(subsets,edges[i].des);
		
		if(x==y){
			return 1;
		}
		
		unionOf(subsets,x,y);
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cycle detection in directed graph (DFS approach) using recursion stack bool vector
bool cycle(int s,vector<int> adj[],vector<bool> &vis, vector<bool> &recSt){
	vis[s]=1;
	recSt[s]=1;
	for(int i=0;i<adj[s].size();i++){
	    if(!vis[adj[s][i]]){
	        if(cycle(adj[s][i],adj,vis,recSt))return true;
	    }else if(recSt[adj[s][i]]){   // if the adj v is in recursion stack and also visited
	            return true;
	    }
	}
	recSt[s]=0;   // mark false after vising all adjacent vertices
	return false;
}
bool isCyclic(int V, vector<int> adj[]) 
{
	vector<bool> vis(V,false);
	vector<bool> recSt(V,false);
	for(int i=0;i<V;i++){
	   	if(!vis[i]){
	   	    if(cycle(i,adj,vis,recSt))return true;
	   	}
	}
	return false;
}


// Cycle detection in directed graph (BFS apprach) using Kahn's Algorithm by computing indegree vector
bool isCyclic(int V, vector<vector<int> > &adj) 
{
	//creating indegree array
	vector<int> indegree(V,0);
	for(int i=0;i<V;i++){
	   	for(int j=0;j<adj[i].size();j++){
	   	    indegree[adj[i][j]]++;
	   	}
	}
	
	queue<int> q;
	   	
	//push all nodes with indegree=0
	for(int i=0;i<V;i++){
	   	if(indegree[i]==0){
	   	    q.push(i);
	   	}
	}
	   	
	int cnt=0;   //counter, if all the vertices are not traversed then there's a cycle
	while(!q.empty()){
	   	int u=q.front();
	   	q.pop();
	   	for(int i=0;i<adj[u].size();i++){
	   	    indegree[adj[u][i]]--;
	   	    if(indegree[adj[u][i]]==0){
	   	        q.push(adj[u][i]);
	   	    }
	   	}
	   	cnt++;
	}
	if(cnt!=V){
	   	return 1;
	}else{
	   	return 0;
	}
}


//Topological sort in directed graph (BFS Based) Kahn's algo
vector<int> topoSort(int V, vector<vectir<int> > &adj) 
{
	vector<int> indegree(V,0);
	for(int i=0;i<V;i++){
	    for(int j=0;j<adj[i].size();j++){
	         ndegree[adj[i][j]]++;
	    }
	}
	queue<int> q;
	for(int i=0;i<V;i++){
	   	if(indegree[i]==0){
	        q.push(i);
	   	}
	}
	vector<int> topo;
	while(!q.empty()){
	  	int u=q.front();
	    q.pop();
	   	topo.push_back(u);
	 	for(int i=0;i<adj[u].size();i++){
	      	indegree[adj[u][i]]--;
	       	if(indegree[adj[u][i]]==0){
	          	q.push(adj[u][i]);
	      	}
	   	}	
	}
	return topo;
}

//Topological sort in directed graph (DFS based) stack 
void dfs(int s,vector<int> adj[],stack<int> &st, vector<bool> &vis ){
	vis[s]=1;
	for(int i=0;i<adj[s].size();i++){
	    if(vis[adj[s][i]]==false){
	        dfs(adj[s][i],adj,st,vis);
	    }
	}
	st.push(s);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
	vector<bool> vis(V,false);
	stack<int> st;
	for(int i=0;i<V;i++){
 		if(!vis[i]){
    	dfs(i,adj,st,vis);
		}
	}
	vector<int> topo;
	while(!st.empty()){
	    topo.push_back(st.top());
	    st.pop();
	}
	return topo;
}


// Dijkstra (minimum distance of all vertices from source) using set
// yet to implement (update the key, in order to avoid repetition)
vector<int> dijkstra(int V,int s,vector<vector<pair<int,int> > > &adj){
	set<pair<int,int> > s;
	vector<int> dist(V,INT_MAX);
	dist[0]=0;
	vector<bool> vis(V,false);
	s.insert({0,0});
	vis[0]=1;
	
	while(s.size()>0){
		pair<int,int> cur=*s.begin();
		s.erase(cur);
		int w=cur.first;
		int u=cur.second;
		
		vis[u]=1;
		
		for(int i=0;i<adj[u].size();i++){
			if(vis[adj[u][i]]==false && dist[adj[u][i].first]>dist[u]+adj[u][i].second){
				s.erase({dist[adj[u][i].first],adj[u][i].first});
				dist[adj[u][i].first]=dist[u]+adj[u][i].second;
				s.insert({dist[adj[u][i].first],adj[u][i].first});
			}
		}
		// print(dist);
	}
	return dist;
}


//////////////////////////////////////////////////////////////
//Kruskals algorithm for find minimum spanning tree 
//using cycle detection by disjoin set and union
struct edge{
	int src,des,wei;
	
};
struct subset{
	int parent,rank;
};
int find(vector<subset> &subsets,int u){
	if(subsets[u].parent!=u){
		return find(subsets,subsets[u].parent);
	}
	return subsets[u].parent;
}
void unionOf(vector<subset> &subsets, int x, int y){
	if(subsets[x].rank<subsets[y].rank){
		subsets[x].parent=y;
	}else if(subsets[x].rank>subsets[y].rank){
		subsets[y].parent=x;
	}else{
		subsets[x].parent=y;
		subsets[y].rank++;
	}
}
bool cmp(edge a,edge b){
	return a.wei<b.wei;
}
int kruskal(int V, vector<vector<pair<int,int> > > &adj){
	int mst=0;
	vector<edge> edges;
	for(int i=0;i<adj.size();i++){
		for(int j=0;j<adj[i].size();j++){
			edge e;
			e.src=i;
			e.des=adj[i][j].first;
			e.wei=adj[i][j].second;
			edges.push_back(e);
		}
	}
	sort(edges.begin(),edges.end(),cmp);
	int e=0;
	int i=0;
	vector<subset> subsets(V);
	for(int i=0;i<V;i++){
		subsets[i].rank=0;
		subsets[i].parent=i;
	}
	while(e<V-1 && i<edges.size()){
		int x=find(subsets,edges[i].src);
		int y=find(subsets,edges[i].des);
		
		if(x!=y){
			unionOf(subsets,x,y);
			e++;
			mst+=edges[i].wei;
		}
		i++;
	}
	return mst;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// find mst using priority queue  // O((E+V)logV)
int prims(int V, vector<vector<pair<int,int> > > &adj){
	int mst=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<bool> vis(V,false);
	pq.push({0,0});
	int e=0;
	while(!pq.empty()&&e<V){
		pair<int,int> p=pq.top();
		pq.pop();
		int u=p.second;
		if(vis[u])continue;
		vis[u]=1;
		mst+=p.first;
		e++;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if(!vis[v])
			pq.push({w,v});
		}
	}
	return mst;
}


/////////////////////////////////////////////////////////////////////////////////
///////////Bellman Ford algorithm for calculating min distance from source
// if negative weights are present, and also to detect negative weight cycles

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	vector<int> dist(n,INT_MAX);
	dist[0]=0;
	for(int i=0;i<n-1;i++){
	    for(int j=0;j<edges.size();j++){
	        int u=edges[j][0];
	        int v=edges[j][1];
	        int w=edges[j][2];
	        if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w){
	            dist[v]=dist[u]+w;
	        }
	    }
	}
	//one extra cycle for 
	for(int j=0;j<edges.size();j++){
	    int u=edges[j][0];
	    int v=edges[j][1];
	    int w=edges[j][2];
	    if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w){
	        return 1;
	    }
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////
// Floyd Warshal( Calculating the min distance b/w every pair of vertices) O(n^3)
// weighted matrix with INF (if edge does not exist)
void floydWarshall(vector<vector<int> > &matrix){
	for(int k=0;k<matrix.size();k++){
		for(int i=0;i<matrix.size();i++){
		    for(int j=0;j<matrix.size();j++){
		        if(matrix[i][k]!=INT_MAX &&  matrix[k][j]!=INT_MAX && matrix[i][j]>matrix[i][k]+matrix[k][j])
		        {
		            matrix[i][j]=matrix[i][k]+matrix[k][j];
		        }
		    }
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////
///Finding articulation point by calculating low value and discovery time
void dfs(int u, vvi &adj,vi &disc, vi &low,vb &vis, vi &par, vb &ap,int &time){
	vis[u]=1;
	time++;
	disc[u]=time;
	low[u]=time;
	int child=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!vis[v]){
			child++;
			par[v]=u;
			dfs(v,adj,disc,low,vis,par,ap,time);
			low[u]=min(low[u],low[v]);
			if(par[u]==-1&&child>1){
				ap[u]=1;
			}
			if(par[u]!=-1&& low[v] >=disc[u]){
				ap[u]=1;
			}
		}else if(v!=par[u]){
			low[u]=min(disc[v],low[u]);
		}
	}
}
vector<int> articulation(int V, vector<vector<int > > adj){
	vector<int> disc(V,0);
	vector<int> low(V,0);
	vector<bool> vis(V,false);
	vector<int> parent(V,-1);
	vector<bool> ap(V,false);
	int time=0;
	
	for(int i=0;i<V;i++){
		if(!vis[i]){
			dfs(i,adj,disc,low,vis,parent,ap,time);
		}
	}
	vi app;
	for(int i=0;i<V;i++){
		if(ap[i]){
			app.pb(i);
		}
	}
	return app;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//Bridges in a graph using low value and disc time
void dfs(int u, vvi &adj,vi &disc, vi &low,vb &vis, vi &par, vpii &br,int &time){
	vis[u]=1;
	time++;
	disc[u]=time;
	low[u]=time;
	int child=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!vis[v]){
			child++;
			par[v]=u;
			dfs(v,adj,disc,low,vis,par,br,time);
			low[u]=min(low[u],low[v]);
			if(low[v] >disc[u]){
				br.push_back({u,v});
			}
		}else if(v!=par[u]){
			low[u]=min(disc[v],low[u]);
		}
	}
}
vector<pair<int,int> > bridge(int V, vector<vector<int > > adj){
	vector<int> disc(V,0);
	vector<int> low(V,0);
	vector<bool> vis(V,false);
	vector<int> parent(V,-1);
	vpii br;
	int time=0;
	
	for(int i=0;i<V;i++){
		if(!vis[i]){
			dfs(i,adj,disc,low,vis,parent,br,time);
		}
	}
	
	return br;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Find strongly connected component if directed graph
// Steps 
// 1. Order the vertices in decreasing order of finish time in DFS( use stack)
// 2. Reverse all the edges
// 3. DFS of the reversed grapg in the order abtained in step 1
void dfs(int u,vector<int> adj[],stack<int> &st,vector<bool> &vis){
	   // cout<<"u="<<u<<endl;
	    vis[u]=1;
	    for(int i=0;i<adj[u].size();i++){
	        int v=adj[u][i];
	        if(!vis[v]){
	            dfs(v,adj,st,vis);
	        }
	    }
	    st.push(u);
	}
	void dfs1(int u,vector<vector<int> > &adj,vector<bool> &vis){
	    vis[u]=1;
	    for(int i=0;i<adj[u].size();i++){
	        int v=adj[u][i];
	        if(!vis[v]){
	            dfs1(v,adj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        vector<vector<int> > rever(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int u=i;
                int v=adj[i][j];
                rever[v].push_back(u);
            }
        }
        vector<bool> vis1(V,false);
        int ans=0;
        while(!st.empty()){
            int t=st.top();
            st.pop();
            // cout<<t<<endl;
            if(!vis1[t]){
                dfs1(t,rever,vis1);
                ans++;
            }
            
        }
        return ans;
    } 