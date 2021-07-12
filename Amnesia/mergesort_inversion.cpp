// Given a binary string S find number of substring which has more 1's than 0's. 
// 
// 1 <= |S| <= 10^6
// or consider array of 1s and -1s
// prefix sum
// or count no. of inversions
// merge sort implementation
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pair<int,int> >
#define pii pair<int,int>
#define mii map<int,int>
#define pqmaxi priority_queue<int>
#define pqmini priority_queue <int,vector<int>,greater<int> >
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mkp make_pair
#define all(v) v.begin(),v.end()
#define input(a,b,n) for(int i=b;i<n;i++){cin>>a[i];}
#define print(a) for(int i=0;i<a.size();i++){cout<<a[i]<<" ";}cout<<endl;
#define printp(p) for(int i=0;i<p.size();i++){cout<<p[i].ff<<" "<<p[i].ss<<endl;}
#define print2(a) for(int i=0;i<a.size();i++){for(int j=0;j<a[i].size();j++){cout<<a[i][j]<<" "}cout<<endl;}
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf=0x3f3f3f3f3f3f3f3f;


int power(int a, int b){
    int res = 1;
    while(b!=0){
        if(b&1){
            res *= a; 
            // res=(res%mod*a%mod)%mod;
        }
        a = (a * a);
        // a=(a%mod*a%mod)%mod;
        b = (b / 2);
    }
    return res;
}

//prime factorization
vi factorize(int n){
	vi ans;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				ans.pb(i);
				n=n/i;
			}
		}
	}
	if(n!=1){
		ans.pb(n);
	}
	return ans;
}

//factorial with/without mod
vi factorial(int n)
{
	vi ans(n+1);
	ans[0] = 1;
	for(int i=1;i<=n;i++)
	{
		ans[i]=ans[i-1]*i;
		// ans[i]=(ans[i-1]%mod*i%mod)%mod;
	}
	return ans;
}
int extendedgcd(int a,int b,int &x,int &y){
	if(a == 0){
		x = 0; y = 1;
		return b;
	}
	int x1,y1;
	int d=extendedgcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}
int nCrmod(int n,int r,vi &fact)
{
	int x1,y1;
	extendedgcd(fact[r],mod,x1,y1);
	int x2,y2;
	extendedgcd(fact[n-r],mod,x2,y2);
	int ans=(fact[n]*((x1+mod)%mod))%mod;
	ans=(ans*((x2+mod)%mod))%mod;
	return ans;
}
void dfs(vvi &adj,int root,vb &vis)
{
	vis[root] = true;
	for(int i=0;i<adj[root].size();i++){
		int v = adj[root][i];
		if(!vis[v])		
			dfs(adj,v,vis);
	}
}
void tf(bool flag){
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int ans;
void merge(vector<int> &a,int l,int m,int r){
	vector<int> left,right;
	for(int i=l;i<=m;i++){
		left.push_back(a[i]);
	}
	for(int i=m+1;i<=r;i++){
		right.push_back(a[i]);
	}
	int i=0;
	int j=0;
	int k=l;
	int n1=left.size(),n2=right.size();
	while(i<n1||j<n2){
		if(i<n1&&j<n2){
			if(left[i]<right[j]){
				a[k]=left[i];
				i++;
				k++;
			}else{
				a[k]=right[j];
				j++;
				k++;
			}
		}else if(i<n1){
			a[k]=left[i];
			i++;
			k++;
		}else{
			a[k]=right[j];
			j++;
			k++;
		}
	}
	return ;
}
void mergeSort(vi &a,int start,int end){
	if(start>=end){
		return;
	}
	
	int mid=(start+end)/2;
	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);
	//extra step to find inversion
	int i=start;
	int j=mid+1;
	while(i<=mid && j<=end){
		if(a[i]>a[j]){
			ans+=(mid-i+1);
			j++;
		}else{
			i++;
		}
	}
	//ends here
	merge(a,start,mid,end);
}
int inversion(vi &pre){
	ans=0;
	mergeSort(pre,0,(int)(pre.size()-1));
	return ans;
}
int32_t main()
{
	fast;
    int t;
    // t=1;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	vi pre(n+1,0);
    	for(int i=1;i<=n;i++){
    		if(s[i-1]=='1'){
    			pre[i]=pre[i-1]+1;
    		}else{
    			pre[i]=pre[i-1]-1;
    		}
    	}
    	vi pr=pre;
    	print(pre);
    	reverse(all(pre));
    	cout<<inversion(pre)<<endl;
    	int cc=0;
    	for(int i=0;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			if(pr[j]>pr[i]){
    				
    				cc++;
    			}
    		}
    	}
    	cout<<cc<<endl;
	}
    return 0;
}
