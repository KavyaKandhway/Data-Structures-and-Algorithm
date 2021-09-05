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
void computeLPS(vi &lps, string &pat){
	lps[0]=0;
	int i=1;
	int len=0;
	int m=pat.size();
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len!=0){
				len=lps[len-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
	return;
}
vi kmp(string &txt,string &pat){
	int n=txt.size();
	int m=pat.size();
	vi lps(m);
	computeLPS(lps,pat);
	// print(lps);
	vi ans;
	int i=0,j=0;
	while(i<n){
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			ans.pb(i-j);
			j=lps[j-1];
		}
		else if(i<n && txt[i]!=pat[j]){
			if(j!=0){
				j=lps[j-1];
			}else{
				i++;
			}
		}
	}
	return ans;
}
int32_t main()
{
	fast;
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
    	string pat,txt;
    	cin>>txt>>pat;
    	print(kmp(txt,pat));
	}
    return 0;
}
