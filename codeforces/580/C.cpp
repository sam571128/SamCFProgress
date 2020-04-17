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

vi adj[100000];
int cat[100000];
int visited[100000];
int ans = 0;

void dfs(int i,int count,int m){
	visited[i] = 1;
	if(cat[i]){
		count++;
	}else{
		count = 0;
	}
	if(count>m){
		return;
	}
	if(adj[i].size()==1&&i!=1){
		ans++;
	}
	for(int j = 0;j < adj[i].size();j++){
		//cout << "Now " << i << " dfs " << adj[i][j] << "\n";
		if(!visited[adj[i][j]])
			dfs(adj[i][j],count,m);
	}
}

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		cat[i] = a;
	}
	for(int i = 0;i < n-1;i++){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);	
	}	
	dfs(1,0,m);
	cout << ans;
}
