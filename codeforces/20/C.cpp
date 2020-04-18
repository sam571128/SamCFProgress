#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
#define pb push_back
#define pf pop_front
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/

int visited[100000];
vector<pair<ll int,ll int>> adj[100005]; // {dist, node}
queue< pair<ll int,ll int> > q;
ll int parent[100000];
vll dijkstra(int i, int v){
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
	vector<ll int> dist(v+1,(ll int)10e12+7);
	pq.push(make_pair(0,i)); // dist and src node
	dist[i] = 0;
	while(!pq.empty()){
		int d = pq.top().second;
		pq.pop();
		
		for(auto x : adj[d]){
			ll int w = x.first;
			ll int v = x.second;
			if(dist[v]>dist[d]+w){
				parent[v] = d;
				dist[v] = dist[d]+w;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	return dist;
}
int main(){
	fastio
	ll int n,m;
	cin >> n >> m;
	while(m--){
		ll int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	vll ans = dijkstra(1,n);
	ll int g = n;
	vll v;
	while(parent[g]!=0||g==1){
		v.pb(g);
		g = parent[g];
	}
	if(find(v.begin(),v.end(),1)==v.end()){
		cout << -1;
	}
	reverse(v.begin(),v.end());
	for(ll i : v){
		cout << i << " ";
	}
}
