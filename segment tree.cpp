#include <bits/stdc++.h>
using namespace std;

void buildST(int ind, int low, int high, vector<int> &a, vector<int> &seg){
	if(low==high){
		seg[ind]=a[low];
		return;
	}
	int mid=(low+high)/2;
	buildST(2*ind+1,low,mid,a,seg);
	buildST(2*ind+2,mid+1,high,a,seg);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	return;
}
int query(int ind,int l,int r,int low,int high,vector<int> &seg){
	if(r<low || l>high){
		return 0;
	}
	if(low>=l && r>=high){
		return seg[ind];
	}
	int mid=(low+high)/2;
	int ll=query(2*ind+1,l,r,low,mid,seg);
	int rr=query(2*ind+2,l,r,mid+1,high,seg);
	return ll+rr;
}
void update(int ind,int x,int val,int low,int high, vector<int> &seg){
	if(low==high && low==x){
		seg[ind]+=val;
		return;
	}
	int mid=(low+high)/2;
	if(x>=low&&x<=mid){
		update(2*ind+1,x,val,low,mid,seg);
	}
	else{
		update(2*ind+2,x,val,mid+1,high,seg);
	}
	seg[ind]=seg[ind*2+1]+seg[ind*2+2];
	return ;
}
void updateLazy(int ind,int l,int r,int val,int low,int high,vector<int> &seg,vector<int> &lazy){
	if(lazy[ind]!=0){
		seg[ind]+=(high-low+1)*lazy[ind];
		if(high!=low){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}
	if(low>=l && high<=r){
		seg[ind]+= (high-low+1)*val;
		if(high!=low){
			lazy[2*ind+1]+=val;
			lazy[2*ind+2]+=val;
		}
		return;
	}
	if(high<l || low>r ){
		return;
	}
	int mid=(low+high)/2;
	updateLazy(2*ind+1,l,r,val,low,mid,seg,lazy);
	updateLazy(2*ind+2,l,r,val,mid+1,high,seg,lazy);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	return ;
}
int queryLazy(int ind,int l,int r,int low,int high,vector<int> &seg,vector<int> &lazy){
	if(lazy[ind]!=0){
		seg[ind]+=(high-low+1)*lazy[ind];
		if(high!=low){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}
	if(low>=l && high<=r){
		return seg[ind];
	}
	
	if(high<l || low>r ){
		return 0;
	}
	int mid=(low+high)/2;
	int ll=queryLazy(2*ind+1,l,r,low,mid,seg,lazy);
	int rr=queryLazy(2*ind+2,l,r,mid+1,high,seg,lazy);
	
	return ll+rr;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> seg(4*n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	buildST(0,0,n-1,a,seg);
	
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		cout<<query(0,l,r,0,n-1,seg)<<endl;
	}
	int u;
	cin>>u;
	for(int i=0;i<u;i++){
		int x,val;
		cin>>x>>val;
		update(0,x,val,0,n-1,seg);
	}
	
	vector<int> lazy(4*n,0);
	cin>>q;
	for(int i=0;i<q;i++){
		int l,r,val;
		cin>>l>>r>>val;
		updateLazy(0,l,r,val,0,n-1,seg,lazy);
	}
	
	cin>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		cout<<queryLazy(0,l,r,0,n-1,seg,lazy)<<endl;
	}
}