class edge{
	public:
		ll src;
		ll dest;
		ll wt;
};

bool compare(edge e1,edge e2){
	return e1.wt < e2.wt;
}

ll getparent(ll v,ll* parent){
	if(parent[v]==v){
		return v;
	}
	return getparent(parent[v],parent);
}

edge* kruskals(edge* edges,ll n,ll e){
	sort(edges,edges+e,compare);
	mk(parent,n,ll)
	mk(output,n-1,edge)
	for(ll i=0;i<n;i++){
		parent[i]=i;
	}
	ll cnt=0;
	ll i=0;
	while(cnt<(n-1)){
		ll s=edges[i].src;
		ll d=edges[i].dest;
		ll v1=getparent(s,parent);
		ll v2=getparent(d,parent);
		if(v1!=v2){
			output[cnt]=edges[i];
			cnt++;
			parent[v1]=v2;
		}
		i++;
	}
	delete[] parent;
	return output;
}
