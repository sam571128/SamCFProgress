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

ll int money[100005];
int visited[100005];
vi adj[100005];

ll int dfs(int i){
	visited[i] = 1;
	ll int mon = money[i];
	for(int j = 0;j < adj[i].size();j++){
		if(!visited[adj[i][j]]){
			mon = min(dfs(adj[i][j]),mon);
		}
	}
	return mon;
}
int main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> money[i];
	}
	while(m--){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll int sum = 0;
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			sum+=dfs(i);
		}
	}
	cout << sum;
}
