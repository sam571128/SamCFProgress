#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int x[2001],y[2001];
ll dist(int u,int v){
	return abs(x[u]-x[v])+abs(y[u]-y[v]);
}
int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i];
	}
	int c[n];
	for(int i = 0;i < n;i++)
		cin >> c[i];
	int k[n];
	for(int i = 0;i < n;i++)
		cin >> k[i];
	ll ans = 0;
	vector<int> powerplant;
	vector< pair<int,int> > connect;
	int visited[n] = {};
	vector<int> parent(n,-1);
	for(int i = 0;i < n;i++){
		int mi = INT_MAX;
		int u = -1;
		for(int j = 0;j < n;j++){
			if(visited[j]) continue;
			if(c[j] < mi){
				mi = c[j];
				u = j;
			}
		}

		ans += mi;
		visited[u] = true;
		if(parent[u] == -1)
			powerplant.push_back(u);
		else
			connect.push_back({parent[u],u});

		for(int j = 0;j < n;++j){
			if(j==u) continue;
			if(c[j] > (k[u]+k[j])*dist(u,j)){
				c[j] = (k[u]+k[j])*dist(u,j);
				parent[j] = u;
			}
		}
	}
	cout << ans << "\n";
	cout << powerplant.size() << "\n";
	for(int i = 0;i < powerplant.size();i++){
		cout << powerplant[i] + 1 << " ";
	}
	cout << "\n";
	cout << connect.size() << "\n";
	for(auto p : connect){
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
}