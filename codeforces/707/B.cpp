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

vpi adj[100000]; //dist,node
int storage[100000];
int dist = (int)10e8+7;
int main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].pb(make_pair(c,b));
		adj[b].pb(make_pair(c,a));
	}	
	vi v;
	while(k--){
		int a;
		cin >> a;
		v.pb(a);
		storage[a] = 1;
	}
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < adj[v[i]].size();j++){
			if(!storage[adj[v[i]][j].second]){
				dist = min(dist,adj[v[i]][j].first);
			}
		}
	}
	if(dist==(int)10e8+7){
		cout << -1;
	}else{
		cout << dist;
	}
}
