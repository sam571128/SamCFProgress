#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

vi adj[100005];
int energy[100005];
int spent(int i){
	energy[i] = 0;
	int sum = 0;
	for(int j = 0;j < adj[i].size();j++){
		sum+=energy[adj[i][j]];
	}
	return sum;
}
int main(){
	fastio
	int n,m;
	cin >> n >> m;
	vpi v; //{energy,count
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		energy[i] = a;
		v.pb(make_pair(a,i));
	}
	sort(v.rbegin(),v.rend());
	while(m--){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int ans = 0;
	for(int i = 0;i < v.size();i++){
		int a = v[i].second;
		ans+=spent(a);
	}
	cout << ans;
}
