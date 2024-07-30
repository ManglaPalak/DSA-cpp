#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& trees,int n,int m,int mid){
	long long sum=0;
	
	for(int i=0;i<n;i++){
		if(trees[i]>mid){
			
			sum=sum+(trees[i]-mid);
		
			
		}	
	}
	if(sum>=m){
		return true;
	}
	return false;
}
int heightSet(vector<int>& trees,int n,int m){
	sort(trees.begin(),trees.end());
	int start=0;
	int end=trees[n-1];
	int ans=-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if (isPossible(trees,n,m,mid)){
			ans=mid;
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> trees(n);
	for(int i=0;i<n;i++){
		cin>>trees[i];
	}
	int ans=heightSet(trees,n,m);
	cout<< ans << endl;
	return 0;
}
