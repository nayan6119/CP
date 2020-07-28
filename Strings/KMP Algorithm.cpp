int* getlps(char* t,int m){
	int* lps=new int[m];
	lps[0]=0;
	int i=1;
	int j=0;
	while(i<m){
		if(t[i]==t[j]){
			lps[i]=j+1;
			j++;
			i++;
		}else{
			if(j!=0){
				j=lps[j-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

int kmpSearch(char* s,int n,char* t,int m){
	int i=0;
	int j=0;
	int* lps=getlps(t,m);
	while(i<n&&j<m){
		if(s[i]==t[j]){
			i++;
			j++;
		}else{
			if(j!=0){
				j=lps[j-1];
			}else{
				i++;
			}
		}
	}
	if(j==m){
		return i-m;
	}
	return -1;
}
