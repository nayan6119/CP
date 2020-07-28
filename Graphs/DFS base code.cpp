void print(ll** edges,ll n,ll s,ll e,bool* visited,vr &ans){
	if(s==e){
		ans.pb(e);
		return;
	}
	visited[s]=true;
	for(ll i=0;i<n;i++){
		if(s==i){
			continue;
		}
		if(edges[s][i]==1){
			if(!visited[i]){
				print(edges,n,i,e,visited,ans);
				if(ans.size()!=0){
					ans.pb(s);
					return;
				}
			}
		}
	}
	return;
}

void DFS(ll** edges,ll n,ll s,ll e){
	mk(visited,n,bool)
	for(ll i=0;i<n;i++){
		visited[i]=false;
	}
	vr ans;
	print(edges,n,s,e,visited,ans);
	for(ll i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	delete[] visited;
}
