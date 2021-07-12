// Fenwik Tree or Binary Indexed Tree
// used only when the range operation is associative
// examples -sum, product, (not gcd) , matrix sum, matrix multiplication if 
// det(M)!=0
#include <bits/stdc++.h>
using namespace std;
void update(vector<int> &bit,int val,int ind){
	for(int i=ind;i<bit.size();i+=(-i)&i){
		bit[i]+=val;
	}
	return;
}
int query(vector<int> &bit, int ind){
	int sum=0;
	for(int i=ind;i>0;i-=(-i)&(i)){
		sum+=bit[i];
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> bit(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(bit,a[i],i);
	}
	// cout<<query(bit,10)-query(bit,9-1)<<endl;
	// update(bit,2,1);
	// cout<<query(bit,1)<<endl;
}