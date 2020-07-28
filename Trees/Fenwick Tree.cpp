void update(ll index,ll value,ll* BIT,ll n){

	for(;index <= n;index += index&(-index)){
		BIT[index] += value;
	}
}

ll query(ll index,ll* BIT){
	ll sum=0;
	for(;index >0;index -= index&(-index)){
		sum += BIT[index];
	}
	return sum;
}
