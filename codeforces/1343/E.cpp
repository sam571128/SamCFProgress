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

vector<vi> adj;
const int INF = 1e9;

vi bfs(int s,int n){
	vi dist(n,INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : adj[v]){
			if(dist[x] == INF){
				dist[x] = dist[v] + 1;
				q.push(x);
			}
		}
	}
	return dist;
}
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,m,a,b,c;
		cin >> n >> m >> a >> b >> c;
		--a,--b,--c;
		vi p(m);
		for(int i = 0;i < m;i++){
			cin >> p[i];
		}
		sort(p.begin(),p.end());
		vll pref(m+1,0);
		for(int i = 1;i < pref.size();i++){
			pref[i] = pref[i-1]+p[i-1];
		}
		adj = vector<vi>(n);
		for(int i = 0;i < m;i++){
			int x,y;
			cin >> x >> y;
			x--;
			y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		vi da = bfs(a,n);
		vi db = bfs(b,n);
		vi dc = bfs(c,n);
		ll int ans = 1e18;
		for(int i = 0;i < n;i++){
			if(da[i]+db[i]+dc[i]>m) continue;
			ans = min(ans,pref[db[i]]+pref[da[i]+db[i]+dc[i]]);
		}
		cout << ans << "\n";
	}
}
