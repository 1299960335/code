int  jiafa(int n,int m){
	while(n){
		size_t num=(n&m)<<1;
		n^=m;
		m=num;
	}
	return n;
}