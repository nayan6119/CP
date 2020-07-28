ll gmv(bool* visited,ll* weight,ll n){
	ll mv=-1;
	for(ll i=0;i<n;i++){
		if((!visited[i])&&((mv==-1)||(weight[mv]>weight[i]))){
			mv=i;
		}
	}
	return mv;
}

void prims(ll** edges,ll n){
	mk(visited,n,bool)
	mk(parent,n,ll)
	mk(weight,n,ll)
	
	for(ll i=0;i<n;i++){
		weight[i]=inf;
		visited[i]=false;
	}
	parent[0]=-1;
	weight[0]=0;
	
	for(ll i=0;i<n-1;i++){
		ll mv=gmv(visited,weight,n);
		visited[mv]=true;
		for(ll j=0;j<n;j++){
			if(edges[mv][j]!=0&& !visited[j]){
				if(weight[j]>edges[mv][j]){
					weight[j]=edges[mv][j];
					parent[j]=mv;
				}
			}
		}
	}
	for(ll i=1;i<n;i++){
		if(parent[i]<i){
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<"\n";
		}else{
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<"\n";
		}
	}
	delete[] weight;
	delete[] parent;
	delete[] visited;
}

