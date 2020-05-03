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

const int INF = 1e9;
int main(){
	fastio
	int n;
	cin >> n;
	ll int adj[n][n];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> adj[i][j];
		}
	}
	int e;
	cin >> e;
	while(e--){
		ll int x,y,d;
		cin >> x >> y >> d;
		x--,y--;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(adj[i][x]+d+adj[y][j]<adj[i][j]) adj[i][j] = adj[i][x]+d+adj[y][j];
				if(adj[i][y]+d+adj[x][j]<adj[i][j]) adj[i][j] = adj[i][y]+d+adj[x][j];
			}
		}
		ll int sum = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				sum+=adj[i][j];
			}
		}
		cout << sum << " ";
	}
	
	
}
