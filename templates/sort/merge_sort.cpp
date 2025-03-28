i64 ans = 0;
std::vector<int> v(N,0);
std::vector<int> tmp(N,0);

void merge_sort(std::vector<int> &v,int l,int r){
	if(l>=r) return;
	int mid = l+r>>1;
	merge_sort(v,l,mid);
	merge_sort(v,mid+1,r);
	int k = 0,i = l,j = mid+1;
	while(i<=mid&&j<=r){
		if(v[i]<=v[j]) tmp[k++] = v[i++];
		else tmp[k++] = v[j++],ans+=mid-i+1;
	}
	while(i<=mid) tmp[k++] = v[i++];
	while(j<=r) tmp[k++] = v[j++];
	for(int i = l,j = 0;i<=r;++i,++j) v[i] = tmp[j];
}
