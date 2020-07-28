void print(ll** edges,ll n,ll sv,bool* visited){
	queue<ll> pv;
	pv.push(sv);
	visited[sv]=true;
	while(!pv.empty()){
		ll cv=pv.front();
		pv.pop();
		cout<<cv<<" ";
		for(ll i=0;i<n;i++){
			if(i==cv){
				continue;
			}
			if(edges[cv][i]==1&&!visited[i]){
				pv.push(i);
				visited[i]=true;
			}
		}
	}
}

void BFS(ll** edges,ll n){
	mk(visited,n,bool)
	for(ll i=0;i<n;i++){
		visited[i]=false;
	}
	for(ll i=0;i<n;i++){
		if(!visited[i]){
			print(edges,n,i,visited);
		}
	}
	delete[] visited;
}

