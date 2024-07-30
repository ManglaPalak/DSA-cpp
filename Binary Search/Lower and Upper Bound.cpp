int upper(int x,vector<int>& a){
	int s=0;
	int e=a.size()-1;
	int ans=-1;
	int mid=s+(e-s)/2;
	while(s<=e){
		if (a[mid]==x){
			return a[mid];
		}
		else if (a[mid]>x){
			ans=a[mid];
			e=mid-1;
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}
int lower(int x,vector<int>& a){
	int s=0;
	int e=a.size()-1;
	int ans=-1;
	int mid=s+(e-s)/2;
	while(s<=e){
		if (a[mid]==x){
			return a[mid];
		}
		else if (a[mid]<x){
			ans=a[mid];
			s=mid+1;
		}
		else{
			e=mid-1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int,int> ans;
	ans.first=lower(x,a);
	ans.second=upper(x,a);
	return ans;
}
