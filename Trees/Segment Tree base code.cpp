void buildtree(ll* tree,ll* a,ll start,ll end,ll treeNode){
	if(start==end){
		tree[treeNode]=a[start];
		return;
	}
	ll mid=(start+end)/2;
	buildtree(tree,a,start,mid,2*treeNode);
	buildtree(tree,a,mid+1,end,2*treeNode+1);
	tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updatetree(ll* tree,ll* a,ll start,ll end,ll treeNode,ll idx,ll value){
	if(start==end){
		a[idx]=value;
		tree[treeNode]=value;
		return;
	}
	ll mid=(start+end)/2;
	if(idx>mid){
		updatetree(tree,a,mid+1,end,2*treeNode+1,idx,value);
	}else{
		updatetree(tree,a,start,mid,2*treeNode,idx,value);
	}
	tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}

ll querytree(ll* tree,ll start,ll end,ll treeNode,ll left,ll right){
	if(right<start||left>end){
		return inf;
	}
	if(start>=left&&end<=right){
		return tree[treeNode];
	}
	ll mid=(start+end)/2;
	ll ans1=querytree(tree,start,mid,2*treeNode,left,right);
	ll ans2=querytree(tree,mid+1,end,2*treeNode+1,left,right);
	
	return min(ans1,ans2);
}
